#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>


int main()
{
    char cmd[100],*argv[30];
    int ch1,ch2,ch3,ch4,ch5,ch6;
    int s1,s2,s3,s4,s5,s6;

    int i=0;
    char *ptr;
    ch1=fork();
    if(ch1==0)
    {
        strcpy(cmd,"gcc -c circle.c");
        ptr = strtok(cmd," ");
        argv[i]=ptr;
        i++;
        do
        {
            ptr=strtok(NULL," ");
            argv[i]=ptr;
            i++;
        } while (ptr != NULL);
        int err =execvp(argv[0],argv);
        if(err<0)
        {
            perror("execvp failed");
        }
        _exit(0);
    }
    ch2=fork();
    if(ch2==0)
    {
        strcpy(cmd,"gcc -c squre.c");
        ptr = strtok(cmd," ");
        argv[i]=ptr;
        i++;
        do
        {
            ptr=strtok(NULL," ");
            argv[i]=ptr;
            i++;
        } while (ptr != NULL);
        int err =execvp(argv[0],argv);
        if(err<0)
        {
            perror("execvp failed");
        }

        _exit(0);
    }
    ch3=fork();
    if(ch3==0)
    {
        strcpy(cmd,"gcc -c rectangle.c");
        ptr = strtok(cmd," ");
        argv[i]=ptr;
        i++;
        do
        {
            ptr=strtok(NULL," ");
            argv[i]=ptr;
            i++;
        } while (ptr != NULL);
        int err =execvp(argv[0],argv);
        if(err<0)
        {
            perror("execvp failed");
        }
        _exit(0);
    }
    ch4=fork();
    if(ch4==0)
    {
        strcpy(cmd,"gcc -c main.c");
        ptr = strtok(cmd," ");
        argv[i]=ptr;
        i++;
        do
        {
            ptr=strtok(NULL," ");
            argv[i]=ptr;
            i++;
        } while (ptr != NULL);
        int err =execvp(argv[0],argv);
        if(err<0)
        {
            perror("execvp failed");
        }
        _exit(0);
        
    }
    waitpid(ch1,&s1,0);
    waitpid(ch2,&s2,0);
    waitpid(ch3,&s3,0);
    waitpid(ch4,&s4,0);
    if(!(WEXITSTATUS(s1)|WEXITSTATUS(s2)|WEXITSTATUS(s3)|WEXITSTATUS(s4)))
    {
    ch5=fork();
    if(ch5==0)
    {
        strcpy(cmd,"gcc -o program.out circle.o squre.o rectangle.o main.o");
        ptr = strtok(cmd," ");
        argv[i]=ptr;
        i++;
        do
        {
            ptr=strtok(NULL," ");
            argv[i]=ptr;
            i++;
        } while (ptr != NULL);
        int err =execvp(argv[0],argv);
        if(err<0)
        {
            perror("execvp failed");
        }
        _exit(0);
        
    }




    }
    
    waitpid(ch5,&s5,0);
    ch6=fork();
    if(ch6==0)
    {
        strcpy(cmd,"./program.out ");
        ptr = strtok(cmd," ");
        argv[i]=ptr;
        i++;
        do
        {
            ptr=strtok(NULL," ");
            argv[i]=ptr;
            i++;
        } while (ptr != NULL);
        int err =execvp(argv[0],argv);
        if(err<0)
        {
            perror("execvp failed");
        }
        _exit(0);
        
    }
    waitpid(ch6,&s6,0);



  
        

    
return 0;
}











