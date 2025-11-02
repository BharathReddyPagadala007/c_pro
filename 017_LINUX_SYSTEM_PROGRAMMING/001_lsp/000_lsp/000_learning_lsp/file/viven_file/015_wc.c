#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>


#define BUF_SIZE 1024

int main(){

	int fd, bytes_read;
	char buffer[BUF_SIZE];
	int line_count =0;


	fd= open("source.txt",O_RDONLY);

	while((bytes_read= read(fd,buffer, BUF_SIZE))>0 ){

		for(int i=0; i<bytes_read; i++){

			if(buffer[i]== '\n'){
				line_count++;
			}
		}
	}

	char count_str[20];

	int len = sprintf(count_str,"%d\n",line_count);
	write(1,count_str,len);
	close(fd);


return 0;
}
