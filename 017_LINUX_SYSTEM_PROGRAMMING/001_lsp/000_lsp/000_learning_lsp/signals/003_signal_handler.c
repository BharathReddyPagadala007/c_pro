#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>

void signal_handler(int sig)
{

printf("signal caught %d 2>SIGINT \n",sig);

}
int main()
{

   struct sigaction sa;
   sa.sa_handler= signal_handler;


  printf("iwaiitng for sig\n");
  sigaction(SIGINT,&sa,NULL);
  while(1){
  printf("procewss running \n");
  sleep(1);
  }


  printf("rsumption\n");
return 0;
}

