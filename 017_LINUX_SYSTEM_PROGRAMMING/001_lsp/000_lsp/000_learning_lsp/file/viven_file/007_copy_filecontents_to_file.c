#include<stdio.h>

#include<fcntl.h>
#include<unistd.h>




int main(){


	int src= open("source.txt",O_RDONLY);


	int dest = open("destination.txt",O_CREAT | O_WRONLY | O_TRUNC, 0644);


	char buffer[128];

	int bytes_read;


	while((bytes_read = read(src,buffer, sizeof(buffer)))>0){
	
		write(dest,buffer,bytes_read);
	
	}

	close(src);
	close(dest);
return 0;
}
