#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/ipc.h>
#include <sys/types.h>
#include <sys/stat.h>


void main(){

	char buf[64];
	int fd;
	int ret;

	printf("waiting for client to connect\n");
       //fd = open("/tmp/fifoobj",O_RDONLY);

//	if(fd<0){
		if((ret= mkfifo("fifoobj",0666))<0)
		{
	         printf("error creating fifo object \n");
		 return ;
		}
		fd = open("fifoobj",O_RDONLY);
//	}

	printf("client connected\n");
	printf("waiitnf for client message\n");
	read(fd,buf,64);
	printf("message receiver : %s\n",buf);

}
