
#include<fcntl.h>

#include<unistd.h>



int main(){
	int fd = open("001_example.txt",O_CREAT | O_WRONLY | O_TRUNC,0644);

//	const char* str = "hello worldi\n";
	write(fd,"hello worldi\n",14);

	close(fd);


return 0;
}



////////////////////////////////////
// the issue of opening 001_example is because of umask
// umask 0022
// or change 
// the mode using 
//  chmod 0644 001_example.txt
