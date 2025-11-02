#include<unistd.h>

int main(){

	if(access("sample.txt",F_OK)==0){
		write(STDOUT_FILENO,"FILE EXISTS\n",12);
	}else{
		write(STDOUT_FILENO,"file doesnt exist\n",20);
	}

return 0;
}
