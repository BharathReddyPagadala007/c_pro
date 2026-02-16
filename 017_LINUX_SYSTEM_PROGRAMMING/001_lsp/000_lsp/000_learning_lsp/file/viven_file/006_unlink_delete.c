#include<unistd.h>

//assume or create  delete_me.txt file exists or else craete one


int main(){

unlink("delete_me.txt");

return 0;
}


/*
 *
 *
 unlink()  deletes  a name from the filesystem.  If that name was the last link to a file and no processes have the file open, the file is deleted and    
       the space it was using is made available for reuse.

       If the name was the last link to a file but any processes still have the file open, the file will remain in existence until the last file  descriptor    
       referring to it is closed.

       If the name referred to a symbolic link, the link is removed.

       If the name referred to a socket, FIFO, or device, the name for it is removed but processes which have the object open may continue to use it.



 */
