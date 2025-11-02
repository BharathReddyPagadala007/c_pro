#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>


void signal_handler(int sig)
{
	printf("signal handler is invoked by SIGINT %d-->\n",sig);


}
int main()
{

	signal(SIGINT,signal_handler);
	printf("waiintg for a signal\n");
	pause();
	printf("process resumes\n");

return 0;
}
