#include<stdio.h>
#include<unistd.h>
#include<sys/shm.h>
#include<sys/wait.h>
#include<stdlib.h>
#define KEY 0x00004444
typedef struct shm
{
    int count;

}shm_t;
int main()
{
    shm_t *ptr;
    int shmid,ret,s,temp;
    shmid = shmget(KEY,sizeof(shm_t),IPC_CREAT|0600);\

    ptr = shmat(shmid,NULL,0);
    shmctl(shmid,IPC_RMID,NULL);
    ptr->count=0;
    ret = fork();
    if(ret == 0)
    {
        for(int i=0;i<1000000;i++)
        {
            temp = ptr->count+1;
            ptr->count=temp;
            printf("child : %d\n",ptr->count);
            //sleep(1);
        }
    }
    else{
        for(int i=1; i<1000000; i++) {
        temp = ptr->count-1;
            ptr->count=temp;
            printf("parent : %d\n",ptr->count);
            //sleep(1);
        }
    }
     waitpid(-1, &s, 0);
        printf("final count: %d\n", ptr->count);
        shmdt(ptr);
        return 0;
}