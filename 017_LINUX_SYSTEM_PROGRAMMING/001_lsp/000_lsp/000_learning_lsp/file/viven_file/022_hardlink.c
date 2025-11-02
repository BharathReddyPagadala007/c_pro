#include<stdio.h>
#include<unistd.h>


int main(){
   
	const char * source = "source.txt";
	const char * hardlink = "hardlink.txt";

	if(link(source,hardlink)){
	 perror("errior");
	 return 1;
	}


	printf("%s hardlink created for file %s. \n",hardlink, source);

return 0;
}
