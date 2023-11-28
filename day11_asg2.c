#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
    int pid1,pid2,pid3,pid4,s1,s2,s3,s4;
    
        printf("child_A--->%d  parent_of_A--->%d\n",getpid(),getppid());
       pid2 = fork();
        if(pid2==0)
        {
            printf("child_B--->%d  parent_of_B--->%d\n",getpid(),getppid());

            pid3=fork();
            if(pid3==0)
            {
                printf("child_C-->%d  parent_of_C--->%d\n",getpid(),getppid());
                pid4=fork();
                 if(pid4==0)
                 {
                      printf("child_D-->%d  parent_of_D--->%d\n",getpid(),getppid());
                      for(int i=0;i<5;i++)
                      {
                        sleep(1);
                      }
                    _exit(4);
                 }  
               for(int i=0;i<5;i++)
                      {
                        sleep(1);
                      }
              _exit(3);
            }
            
            for(int i=0;i<5;i++)
                      {
                        sleep(1);
                      }
              _exit(2);

        }
      
      


    

    for (int i = 0; i < 10; i++)
    {
        printf("parent:%d \n",getpid());
        sleep(1);
        if(i==5)
        {
            waitpid(pid1, &s1, 0);
            
            waitpid(pid2, &s2, 0);
          
            waitpid(pid3, &s3, 0);
           
            waitpid(pid4, &s4, 0);
          


        }
    }
    





}