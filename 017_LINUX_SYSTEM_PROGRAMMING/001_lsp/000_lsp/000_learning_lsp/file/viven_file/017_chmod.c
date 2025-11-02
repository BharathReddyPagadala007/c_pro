#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>



int main(){

if(chmod("file.txt",0444)==-1){

  write(2,"error\n",sizeof("error\n"));
  return 1;
}
write(1,"ronly\n",sizeof("ronly\n"));



return 0;
}
