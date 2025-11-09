#include<stdio.h>
#include<unistd.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(){

	int fd,ret;
	char buf[64]="hello";



	fd= open("file.txt",O_RDONLY);
	
	if(fd<0){
	 printf("open failed\n");
	 return 1;
	}
	printf("file opened successfully\n");

	ret = read(fd, buf,64);

	if(ret<0){
	
	printf("failed to read\n");
	close(fd);
	return 1;
	}
	buf[ret]= '\0';
//	buf[ret]=NULL;
	//printf("%s",buf);

	printf("read %d bytes from file ::= %s \n",ret,buf);


	close(fd);

return 0;
}
