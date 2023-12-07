#include<stdio.h>
#include<pthread.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/shm.h>
#include<sys/wait.h>
#include<semaphore.h>

#define SHM_KEY 0x00001234

typedef struct si
{
    int result;

}si_t;

typedef struct shm
{
    si_t r;
    int a;
    pthread_mutexattr_t ta;
    pthread_mutex_t t;
    sem_t s;
    
   
}shm_t;

shm_t *sh;

void* handler(void * parm)
{
    pthread_mutex_lock(&(sh->t));
    
    printf("hello");
    int * p = (int*) parm;
    sh->r.result = (*p *2*3)/100; 
    pthread_mutex_unlock(&(sh->t));
     sem_post(&(sh->s));
     return NULL;
    



}
void* handler1(void *parm)
{
     sem_wait(&(sh->s));
   pthread_mutex_lock(&(sh->t));
    //
    printf("\nSimple INT --> %d\n",sh->r.result);
   pthread_mutex_unlock(&(sh->t)); 
   return NULL;
    
}
 
int shmid;
int main()
{
     
   

    shmid = shmget(SHM_KEY,sizeof(shm_t),IPC_CREAT|0666);
    sh =(shm_t *) shmat(shmid,NULL,0);
  
    int p,s,s1;
    
    sem_init(&(sh->s),1,0);
    pthread_mutexattr_init(&(sh->ta));
    pthread_mutex_init(&(sh->t),&(sh->ta));
    pthread_mutexattr_setpshared(&(sh->ta),PTHREAD_PROCESS_SHARED);
     shmctl(shmid,IPC_RMID,NULL);

int ret=fork();

//child
if(ret==0)
{
    
    int p;
    printf("Enter princile amount\n");
    scanf("%d",&p);
    pthread_t t1;
    pthread_create(&t1,NULL,handler,(void*)&p);
    pthread_join(t1,NULL);
    _exit(0);

}

int ret1=fork();
if(ret1==0)
{
    pthread_t t2;
    pthread_create(&t2,NULL,handler1,NULL);
    pthread_join(t2,NULL);
    _exit(0);

}
waitpid(ret1,&s,0);
waitpid(ret,&s1,0);

return 0;
}

