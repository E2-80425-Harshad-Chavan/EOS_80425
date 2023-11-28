#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(void)
{
    int ret, s, count=0;

    while(1)
    {
        ret = fork();
        if(ret == -1)
            break;
        else if(ret == 0)
        {
            sleep(10);
            _exit(0);
        }
        else
        {
            count++;
        }
    }

    // printf("Max child count : %d\n", count);

    while(waitpid(-1, &s, 0) > 0)
        ;

    printf("Max child count : %d\n", count);

    return 0;
}