#include<stdio.h>
#include<sys/stat.h>
#include<time.h>


int main(){
  struct stat filestat;
  const char * filename = "source.txt";


  stat(filename,&filestat);

  time_t modified_time = filestat.st_mtime;
  char time_str[30];

  struct tm* time_info = localtime(&modified_time);
  strftime(time_str,sizeof(time_str),"%Y-%m-%d %H:%M:%S",time_info);

  printf("last modified time of %s : %s\n",filename,time_str);


return 0;
}

