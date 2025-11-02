#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <errno.h>



struct message{
 long msg_type;
 char msg_text[100];
};



int main(){

	key_t key;
	int msgid;
	struct message msg;

	key = ftok("/tmp/msgqueue_file",65);



	msgid = msgget(key,  IPC_CREAT | 0666);

	printf("sender :: message queu craeted with ide :: %d\n",msgid);

	printf("enter message type: ");
	scanf("%ld",&msg.msg_type);

	getchar();

	printf("enter the message text\n");

	fgets(msg.msg_text,sizeof(msg.msg_text,stdin),stdin);

	size_t len = strlen(msg.msg_text);

	if(len > 0 && msg.msg_text[len -1]=='\n'){
	   msg.msg_text[len -1]= '\0';
	}

	msgsnd(msgid,&msg, strlen(msg.msg_text)+1,0);


	printf("sender :: mesage sent successfully : type:: %ld, text=%s\n",msg.msg_type,msg.msg_text);
	

	 


return 0;
}
