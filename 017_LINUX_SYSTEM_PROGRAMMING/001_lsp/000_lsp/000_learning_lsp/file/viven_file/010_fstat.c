#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>


int main(){

	struct stat file_info;


	int fd= open("source.txt",O_RDONLY);

	fstat(fd,&file_info);
	printf("file size:: %ld bytes\n",file_info.st_size);

	close(fd);



return 0;
}
