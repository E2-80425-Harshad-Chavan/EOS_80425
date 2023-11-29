#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
    
      
    
    int i;
    char cmd[100],*argv[30];
    char *ptr;
    int ret,err,s;
    
        i=1;
    
    printf("input process id and a signal number  ");
    gets(cmd);
    ptr = strtok(cmd," ");
    argv[0]="kill";
    argv[i]=ptr;
    i++;
    do
    {
        ptr=strtok(NULL," ");
        argv[i]=ptr;
        i++;
    } while (ptr != NULL);
    
    
        ret = fork();
        if(ret == 0)
        {
            execvp(argv[0], argv);
            
            

        }
        else
        {
            waitpid(-1,&s,0);
        }
        

    
return 0;
}