#include<stdio.h>
#include<stdlib.h>
#include<sys/mman.h>

#include<fcntl.h>
#include<unistd.h>
#include<string.h>


#define FILE_SIZE 128

int main()
{

	int fd = open("tempfile.txt",O_RDWR | O_CREAT | O_TRUNC ,0666);

	lseek(fd,FILE_SIZE -1 ,SEEK_SET);
	write(fd,"",1);

	char *mapped = mmap(NULL, FILE_SIZE,PROT_READ | PROT_WRITE , MAP_SHARED,fd,0);

	strcpy(mapped,"hello worlds of mmap");

	printf("mapped memory's content: %s\n",mapped);

	
	munmap(mapped,FILE_SIZE);
	close(fd);
	remove("tempfile.txt");




return 0;
}
