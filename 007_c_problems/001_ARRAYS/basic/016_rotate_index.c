#include<stdio.h>

int main()

{
int arr[7]={4,5,6,7,1,2,3};
int n=7;
int i,index;
for(i=0;i<n;i++){

if(arr[i-1]>arr[i]){

	index=i;

}
}
printf("%d-->%d\n",index,arr[index]);

return 0;
}
