#include<stdio.h>
#include<dirent.h>


int main(){
    //DIR * dir = opendir("TEST");
    DIR * dir = opendir("TEST_DIR");

    if(dir){
     printf("directory TEST exists\n");
     closedir(dir);
    }else{
	    printf("directory doesnt exist\n");
    
    }



return 0;
}
