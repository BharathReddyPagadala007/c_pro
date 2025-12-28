#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>

/*
 *
 *
 *   a socket created with socket() only exists as a file descriptor inside your process
 *   it will not appaear in 
 *   commands:  netstat ,ss , /proc/net / * ...
 *
 *  until u bind() or connect()


int main(){
	int sfd = socket(AF_INET,SOCK_STREAM,0);
	//AF_INET -->  IPv4
	//SOCK_STREAM ---> TCP
	//0--> default proteocol
	//


	if(sfd < 0){
	perror("socket");
	return 1;
	}


	printf("socket created %d\n",sfd);


return 0;
}
