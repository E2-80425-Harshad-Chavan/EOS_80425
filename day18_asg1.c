#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
#include<semaphore.h>
#include<stdlib.h>

sem_t s;
void * sunbeam(void * parm)
{
   
    char *str ="sunbeam\0";
    for(int i=0; str[i] !='\0';i++)
    {
        printf("%c",str[i]);
        
    }
    printf("\n");
     
    sem_post(&s);

}
void * infotech(void * parm)
{
    sem_wait(&s);
    
    char *str ="infotech\0";
    for(int i=0; str[i] !='\0';i++)
    {
        printf("%c",str[i]);
        //sleep(1);

    }
    

}

int main()
{
    sem_init(&s,0,0);

    pthread_t t1,t2;
    pthread_create(&t1,NULL,sunbeam,NULL);
    pthread_create(&t2,NULL,infotech,NULL);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);

return 0;
}