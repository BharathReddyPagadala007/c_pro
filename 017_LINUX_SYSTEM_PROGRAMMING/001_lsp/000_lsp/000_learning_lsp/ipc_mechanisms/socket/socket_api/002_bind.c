#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<unistd.h>


int main(){


	int sfd = socket(AF_INET,SOCK_STREAM,0);
	if(sfd < 0)  {perror("socket"); return 1;}

	struct sockaddr_in  addr;
	memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = INADDR_ANY;
	addr.sin_port = htons(8080);


	if(bind(sfd,(struct sockaddr*)&addr,sizeof(addr)) < 0){
		perror("bind");
		return 1;
	}
	printf("socket created and bound to port 8080\n");
	printf("press enter to exit:\n");
	getchar();

	close(sfd);


return 0;
}
