#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
	int pid,ppid;
	int pd = fork();

	if (pd==0)
	{
		printf("Child : PPID : %d and PID : %d\n",getppid(),getpid());
		sleep(4);
		printf("Child : PPID : %d and PID : %d\n",getppid(),getpid());
		system("ps -ef");
	}
	else{
		printf("Parent: PPID : %d and PID : %d\n",getppid(),getpid());
		sleep(2);
		exit(0);
	}
	return 0;
}