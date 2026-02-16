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

//==============================================
//
//
//write()
//
//write(fd,buffer_string_address,bytes_read)
//
//
/*=====================================================================
 #include <unistd.h>

       ssize_t write(int fd, const void *buf, size_t count);
*/
//================================================================
//
/*
 *       #include <unistd.h>

       ssize_t read(int fd, void *buf, size_t count);
 *
 *
 */
//===================================================================
// read()
//
//   buffer is buffer string address
//   buffer[128]
//
//
// read(fd,buffer, sizeof(buffer))
//
// ======================================================================
