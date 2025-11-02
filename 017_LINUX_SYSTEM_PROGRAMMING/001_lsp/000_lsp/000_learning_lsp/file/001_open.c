#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<unistd.h>
#include<sys/types.h>




int main()
{


	char buffer[100];
	//int fd = open("newfile1.txt",O_CREAT | O_WRONLY, 0666);
	int fd = open("newfile2.txt",O_CREAT | O_RDWR, 0666);
	printf("fd = %d\n",fd);

	
	
	int read_bytes   = read(fd, buffer ,sizeof(buffer)-1);
	buffer[read_bytes]= '\0';
	if(read_bytes<0)
	{
	printf("u foool check the flags its wronly");
	}
	else if(read_bytes> 100){
	
		printf("undefined behaviour even in worst case u cant read more than the size of buffer array-->%d \n",read_bytes);

	
	}

	printf("%d bytesread.....>%s\n",read_bytes,buffer);
	

////////////////////////////////////////////////////
//
//
//  O_RDWR
//  O_RDONLY
//  O_WRONLY
//
//  -------------------
//
//


	const char* text_tobe_written_from= "u should focus on fundamentakls\n";


		int bytes_written = write(fd, text_tobe_written_from,33);
		printf("bytes_wriiten =%d\n",bytes_written);

	close(fd);


return 0;
}
