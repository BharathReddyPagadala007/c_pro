#include<unistd.h>

//assume or create  delete_me.txt file exists or else craete one


int main(){

unlink("delete_me.txt");

return 0;
}
