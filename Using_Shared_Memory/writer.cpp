//problem with Pipe or Message Queue: information has to pass through the kernel

//system calls used:
/*
ftok(): is use to generate a unique key.

shmget(): int shmget(key_t,size_tsize,intshmflg); upon successful completion, shmget() returns an identifier for the shared memory segment.

shmat(): Before you can use a shared memory segment, you have to attach yourself
to it using shmat(). void *shmat(int shmid ,void *shmaddr ,int shmflg);
shmid is shared memory id. shmaddr specifies specific address to use but we should set
it to zero and OS will automatically choose the address.

shmdt(): When you’re done with the shared memory segment, your program should
detach itself from it using shmdt(). int shmdt(void *shmaddr);

shmctl(): when you detach from shared memory,it is not destroyed. So, to destroy
shmctl() is used. shmctl(int shmid,IPC_RMID,NULL);
*/

#include<stdio.h>
#include<unistd.h>
#include<iostream>
#include<sys/shm.h>
#include<sys/ipc.h>
using namespace std;

int main()
{
	key_t key = ftok("shmfile",65);
	int shmid = shmget(key, 1024 ,0666|IPC_CREAT);
	char *str = (char*) shmat (shmid, (void *) 0, 0);
	cout<<"Write the data to the shared memory : \t"<<endl;
	gets(str);
	cout<<"Data written in the memory: "<<str<<endl;

	//detech the data from shared memory
	shmdt(str);

	return 0;
}