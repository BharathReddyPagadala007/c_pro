#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<unistd.h>

#define FIFO_PATH "tmp/my_fifo"

int main(){

  char message[] = " hellow from sender ";

  int fd;



  mkfifo(FIFO_PATH, 0666);

  fd = open(FIFO_PATH,O_WRONLY);

  printf("sender :: writing message to fifo:: \n");

  write(fd,message,strlen(message)+1);


   printf("Sender: Message sent.\n");

  close(fd);



return 0;
}
