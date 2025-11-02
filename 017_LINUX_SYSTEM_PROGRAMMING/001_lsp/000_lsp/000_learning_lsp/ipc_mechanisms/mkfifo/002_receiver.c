#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>

#define FIFO_PATH "tmp/my_fifo"


int main(){


	char buffer[100];
	int fd;


	mkfifo(FIFO_PATH,0666);

	fd = open(FIFO_PATH,O_RDONLY);


	printf("receiver ::waiting for message ...\n");
	read(fd,buffer,sizeof(buffer));


	 printf("Receiver: Received message: %s\n", buffer);
	close(fd);


return 0;
}
