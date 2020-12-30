#include<iostream>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/shm.h>
using namespace std;

int main()
{
	key_t key = ftok("shmfile",65);

	int shmid = shmget(key,1024, 0666|IPC_CREAT);

	char *str = (char*) shmat(shmid, (void *)0, 0);

	cout<<"Data received from the writer process: \t"<<str<<endl;
//detech from the memory
	shmdt(str);
	//destroying the memory
	shmctl(shmid,IPC_RMID,NULL);

	return 0;
}
