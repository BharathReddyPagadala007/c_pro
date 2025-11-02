#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
#include<sys/ipc.h>



void main(){

	char buf[64]={0};
	int fd;
	int ret;

        fd = open("fifoobj",O_WRONLY);
	if(fd<0){
		printf("failed toopen fifo obj\n");
		return;
	}
	printf("write the message for seerver\n");

	scanf("%s",buf);
	write(fd,buf,strlen(buf));
	printf("mesage sent\n");




}
