#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>


int main()
{
    char cmd[100],*argv[30];
    char *ptr;
    int ret,err,s;
    argv[0]="gcc";
    argv[1]="main1.c";
	argv[2]="circle.c";
	argv[3]="rectangle.c";
	argv[4]="squre.c";
	argv[5]="-o";
	argv[6]="program.out";

    
    
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











