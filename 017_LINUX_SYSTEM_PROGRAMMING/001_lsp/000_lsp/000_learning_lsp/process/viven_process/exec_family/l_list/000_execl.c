#include<stdio.h>
#include<unistd.h>


int main(){

	printf("before execl::  \n");
	execl("/bin/ls","ls","-l",NULL);

	printf("after execl::  \n");
	perror("exec failed");




return 1;
}
