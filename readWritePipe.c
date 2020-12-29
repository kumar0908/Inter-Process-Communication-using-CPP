#include<stdio.h>
#include<unistd.h>
#define MAX 20
int main()
{
	int status;
	int pipefds[2];
	char writeMessage[2][20] = {"Hi","Karan"};
	char readMessage[20];
    char message[20];
    char val[1];
    int t=1;
	status = pipe(pipefds);

	if(status==-1)
	{
		printf("There is some problem in creating the pipe!!");
		return -1;
	}
	while(t)
	{
		printf("Please enter your message to write into the pipe: \t");
	    fgets(message, MAX, stdin);
		printf("Trying to write the message to the pipe : %s",message);
		write(pipefds[1],message, sizeof(message)); //writing the message to the pipe
		read(pipefds[0],readMessage,sizeof(readMessage));
		printf("Message read from the Pipe: %s\t",readMessage);
		printf("*******************************************\t\n");
	}
	return 0;

}