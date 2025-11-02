#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
#include<stdio.h>

int main(){

	int fd;
	char* msg = "good bye\n";

	
	fd = open("source.txt",O_WRONLY | O_APPEND);

	write(fd, msg, sizeof(msg));

	close(fd);
	

return 0;
}
