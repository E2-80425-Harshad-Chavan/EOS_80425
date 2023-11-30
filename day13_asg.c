#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/msg.h>
#define U_MSG  0x00001235
typedef struct msg
{
long type;
int a;
int b;

}msg_t;
int main()
{


int ret,mid,s;
//create msg
mid = msgget(U_MSG,IPC_CREAT | 0600);
if(mid<0)
{
	perror("msg Failed");
}

ret=fork();
	if(ret == 0)
	{
	msg_t m1;
	m1.type=99;
	 printf("enter num1 and num2\n");
  	scanf("%d%d",&m1.a,&m1.b);
  	msgsnd(mid,&m1,8,0);

	msgrcv(mid,&m1,8,9,0);
	printf("sum = %d\n",m1.a);



	}
else
{
msg_t m1;
m1.type =99;

msgrcv(mid,&m1,8,99,0);

m1.a=m1.a+m1.b;
m1.type=9;
msgsnd(mid,&m1,8,0);


waitpid(-1,&s,0);
msgctl(mid,IPC_RMID,NULL);
}
return 0;
}
