#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/socket.h>
#include <sys/un.h>

#define PATH "/tmp/harshad_unix"

int main()
{
    struct sockaddr_un cli_add;
    int cli_fd;
     typedef struct str
    {
    	int num1;
    	int num2;
    
	}str_t;
	str_t str;
    cli_fd = socket(AF_UNIX,SOCK_STREAM,0);
    if(cli_fd<0)
    {
        printf("failed to create socket...");
    }
    memset(&cli_add, 0, sizeof(cli_add));
    cli_add.sun_family = AF_UNIX;
    strcpy(cli_add.sun_path,PATH);
   
    int r =connect(cli_fd,(struct sockaddr *)&cli_add,sizeof(cli_add));
    if(r<0)
    {
        printf("------failed to connect------");
    }
    printf("enter two nos \n");
    scanf("%d",&str.num1);
    scanf("%d",&str.num2);
    int rt =write(cli_fd,&str,sizeof(str));
    if(rt==0)
    {
        printf("write sucssfully!!");
    }
    printf("Waiting for msg-------");
    read(cli_fd,&str,sizeof(str));
    printf("sum->%d",str.num1);
    close(cli_fd);
    return 0;
}
