#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/socket.h>
#include <sys/un.h>

#define PATH "/tmp/harshad_unix"
int main()
{
    int ret,cli_fd,server_fd;
    //char str[100];
    typedef struct str
    {
    	int num1;
    	int num2;
    
	}str_t; 
	str_t str;
	socklen_t socklen;
    
    struct sockaddr_un server_add,cli_add;
    server_fd = socket(AF_UNIX,SOCK_STREAM,0);
    if(server_fd<0)
    {
        printf("socket failed to create!!");
    }
    memset(&server_add,0,sizeof(server_add));
    server_add.sun_family = AF_UNIX;
    strcpy(server_add.sun_path,PATH);
    ret = bind(server_fd,(struct sockaddr *)&server_add,sizeof(server_add));
    if(ret<0)
    {
        printf("........failed to  bind.......");
    }
    listen(server_fd,5);


   // while (1)
    {    
    memset(&cli_add,0,sizeof(cli_add));
    cli_add.sun_family = AF_UNIX;
    strcpy(cli_add.sun_path,PATH);
    socklen = sizeof(cli_add);
    cli_fd = accept(server_fd,(struct sockaddr *)&cli_add,&socklen);
    if(cli_fd < 0)
    {
        printf("Failed to to create clifd----- ");
    }
    }

    printf("Waiting for msg-------");
    read(cli_fd,&str,sizeof(str));
    str.num1=str.num1+str.num2;
    printf("send back to client ");
    write(cli_fd,&str,sizeof(str)-sizeof(int));
    
    //printf("\n-->%s",str);

    close(server_fd);
    close(cli_fd);
    shutdown(server_fd, SHUT_RDWR);

}



























