#include<stdio.h>
#include<unistd.h>
int main()
{
	int status1,status2;
	char message1[20] = {"Hi Karan"}, message2[20] = {"Keep Working"};
	char readMess1[20], readMess2[20];

	int pipefds1[2], pipefds2[2];
	int pd;
	

	status1 = pipe(pipefds1);

	if(status1==-1)
	{
		printf("There is some problem in creating the pipe!!\n");
		return -1;
	}
	status2 = pipe(pipefds2);
	if(status2==-1)
	{
		printf("There is some problem in creating the second pipe!!\n");
		return -1;
	}
	 pd = fork();

//child process will write to the the second pipe and read from the first pipe 
	if(pd!=0)
	{
		close(pipefds1[1]); //don't write to the first pipe
		close(pipefds2[0]); //don't read from the second pipe

		//reading from the first pipe

		write(pipefds1[1],message1, sizeof(message1));
		read(pipefds2[0],readMess2,sizeof(readMess2));

		printf("Parent: message written to the pipe2 : %s\n",message1);
		printf("Parent: message read from the pipe 1 : %s\n",readMess2);

	}
	else
	{
		close(pipefds1[0]); //don't write to the second pipe
		close(pipefds2[1]); //don't read from the first pipe

		write(pipefds2[1],message2, sizeof(message2));
		read(pipefds1[0],readMess1, sizeof(readMess1));

		printf("Child: message written to the pipe2 : %s\n",message2);
		printf("Child: message read from the pipe 1 : %s\n",readMess1);

	}


	return 0;
}