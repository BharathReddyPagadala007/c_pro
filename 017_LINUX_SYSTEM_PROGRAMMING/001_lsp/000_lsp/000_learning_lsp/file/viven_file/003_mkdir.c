#include<fcntl.h>
#include<unistd.h>


int main(){


	mkdir("TEST_DIR",0755);

return 0;
}


//=================================
//  0 7 5 5
//  7 -> 111    rwx u
//  5 -> 101	r-x g
//  5 -> 101	r-x n
//  -----------------------
//
