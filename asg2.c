#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<signal.h>
#include<sys/wait.h>
void handler(int s);


int main()
{
    signal(SIGINT, handler);
      
    
    int i;
    char cmd[100],*argv[30];
    char *ptr;
    int ret,err,s;
    while (1)
    {
        
    
    i=0;
    printf("\033[1;31mH_shell-> \033[0m");
    //printf("h_shell-> ");
    gets(cmd);
    ptr = strtok(cmd," ");
    argv[i]=ptr;
    i++;
    do
    {
        ptr=strtok(NULL," ");
        argv[i]=ptr;
        i++;
    } while (ptr != NULL);
    if((strcmp(cmd,"^c") )&& (strcmp(cmd,"")))
    {
    if(strcmp(argv[0],"exit")==0)
    {
        _exit(0);
    }else if(strcmp(argv[0],"\n")==0)
    {
        printf("\033[1;31mH_shell-> \033[0m");
        
    }
    
    else
    {
        ret = fork();
        if(ret == 0)
        {
            err = execvp(argv[0], argv);
            if(err < 0)
            {
                perror("bad command");
                _exit(1);
            }
            

        }
        else
        {
            waitpid(-1,&s,0);
        }
        
    }
    }
    }
return 0;
}
void handler(int s) 
{
    printf("signal : %d\n", s);
    
    
    return;
}
