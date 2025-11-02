#include<stdio.h>
#include<string.h>


int main()
{


	struct Point{
		int x;
		int y;

	};
	struct Point p1 ={10,20};
	struct Point p2;

	memcpy(&p2,&p1,sizeof(int));


	printf("p1.x=%d  p1.y=%d\n",p1.x,p1.y);
	printf("p2.x=%d  p2.y=%d\n",p2.x,p2.y);




return 0;
}
////////////////////////////////////////////////
/*
 *
 tai_wsl@tailung:/mnt/g/embsys/profile/cpro/LSP/virtualmemory/memcpy$ ./a.out
p1.x=10  p1.y=20
p2.x=10  p2.y=0
*/

//////////////////////////////////////////////////////

