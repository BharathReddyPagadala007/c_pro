#include<fcntl.h>
#include<unistd.h>

int main(){
   


	int fd= open("001_example.txt",O_RDONLY);

	char buffer[128];
	int bytes_read;


	while((bytes_read  = read(fd,buffer,sizeof(buffer)))>0){
	
	write(STDOUT_FILENO,buffer, bytes_read);
	
	}
	close(fd);


return 0;
}
