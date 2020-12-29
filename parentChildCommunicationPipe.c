#include<stdio.h>
#include<unistd.h>
int main()
{
	int status;
	int pipefds[2];
	char messageBuffer[2][20] = {"Hi","Karan"};
	char readMessage[20];

	int pid =0;
	int pd;
	status = pipe(pipefds);
 	pd = fork();
//child process will try to read from the pipe written by the parent process.
 	if (pd==0)
 	{
       read(pipefds[0],readMessage,sizeof(readMessage));
       printf("\nMessage read from the Pipe by the child process : %s\t",readMessage);
 	}
 	else
 	{
 		sleep(5);
 		write(pipefds[1],messageBuffer[1],sizeof(messageBuffer[1]));
 		printf("\nMessage written by the parent process into the pipe : %s\t",messageBuffer[1]);
 	}
return 0;

}