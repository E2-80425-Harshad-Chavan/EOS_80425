#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<signal.h>
int main()
{
     int sin,pid;
    while (1)
    {
        
   
    printf("input process id  \n");
    scanf("%d",&pid);
    printf("input signal number  \n");
    scanf("%d",&sin);
    kill(pid,sin);
    }
}