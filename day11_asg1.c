#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
void process(int ret);
int cnt=1;
int main() {
    int ret[5],s[5];
    for(int i=0;i<5;i++)
    {
        ret[i]=fork();
        process(ret[i]);
    }


    for(int i=1; i<=10; i++) {
        printf("parent: %d\n", getpid());
        sleep(1);
        if(i==5)
        {
            for(int i=0;i<5;i++)
            {
            waitpid(ret[i], &s[i], 0);
            printf("exit status child %d --> %d\n",i,WEXITSTATUS(s[i]));
            }
        }
    }
    

    return 0;
}
void process(int ret)
{
    if(ret == 0) 
    { 
        
        
            printf("child: %d  parrent->%d \n",getpid(),getppid());
           
            sleep(5);
        
        _exit(0);
    }

}
