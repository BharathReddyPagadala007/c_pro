#include<stdio.h>
#include<sys/types.h>
#include<string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<unistd.h>


int main(){

	int fd;
	char buf[64]="helloworld";
	int ret;



	fd= open("file.txt",O_WRONLY);
	
	if(fd<0){
	 printf("open failed\n");
	 return 1;
	}
	printf("file opened successfully\n");

	ret = write(fd, buf,strlen(buf));

	if(ret<0){
	
	printf("failed to read\n");
	close(fd);
	return 1;
	}
	printf("written %d bytes to file\n",ret);

	close(fd);



return 0;
}
