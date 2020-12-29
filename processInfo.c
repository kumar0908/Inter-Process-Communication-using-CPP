#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
int main()
{
	int mypid, myppid;
	printf("\nProgram to know the PID and Parent Id:\n\n");
	mypid = getpid();
	myppid = getppid();
	printf("Process-id : %d\n",mypid);
	printf("Parent process-id : %d\n",myppid);
	printf("Information about all the processes using system call:\n\n");

	//system("ps -ef");
	return 0;
}