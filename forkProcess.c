#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
	int pid ;
	int pd;
	int ppid;
	ppid = getpid();

	printf("Process-id before fork: %d \n",ppid);

	pd = fork();

	if (pd<0)
	{
		printf("Process creation failed!!\n");
		return -1;
	}
	if (pd==0)
	{
		printf("\nThis is the child process:\n");
		pid = getpid();
		ppid = getppid();
		printf("Process id: %d\t",pid);
		printf("\nParent process id: %d\t",ppid);

	}
	else
	{
		sleep(2);
		printf("This is the parent process: \n");
		pid = getpid();
		ppid = getppid();
		printf("Process id: %d\t",pid);
		printf("\nParent process id: %d\t",ppid);
	}
	return 0;
}