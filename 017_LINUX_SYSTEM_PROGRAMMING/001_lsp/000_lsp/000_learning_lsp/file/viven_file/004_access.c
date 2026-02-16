#include<unistd.h>

int main(){

	if(access("sample.txt",F_OK)==0){
		write(STDOUT_FILENO,"FILE EXISTS\n",12);
	}else{
		write(STDOUT_FILENO,"file doesnt exist\n",20);
	}

return 0;
}

// F_OK checks the existence of file

//================================================================
// access()
//
/*
 * NAME
       access, faccessat, faccessat2 - check user's permissions for a file

SYNOPSIS
       #include <unistd.h>

       int access(const char *pathname, int mode);
  */
//=========================================================================

//
//    
/*    
 *    access() checks whether the calling process can access the file pathname.  If pathname is a symbolic link, it is dereferenced.

       The mode specifies the accessibility check(s) to be performed, and is either the value F_OK, or a mask consisting of the bitwise OR of one or more of
       R_OK, W_OK, and X_OK.  F_OK tests for the existence of the file.  R_OK, W_OK, and X_OK test whether the file exists and grants read, write, and  exe‐
       cute permissions, respectively.

  */
//===================================================================

