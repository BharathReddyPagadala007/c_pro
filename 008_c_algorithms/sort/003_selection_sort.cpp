#include<iostream>
#include<vector>
using namespace std;


 void   selectionSort(vector<int>& arr){
 
	 int n= arr.size();
 int i,j,temp,min_index;

 for(i=0; i<n;i++){
   min_index= i;

   for(j=i+1; j<n; j++){
   
    if(arr[j]<arr[min_index]){
      min_index =j;
    }
   }

   swap(arr[min_index],arr[i]);
 
 }
 
 }
//////////////////////////////////////////
//


void printArray(vector<int>& arr){

for(int num: arr){

cout<< num << " ";
}

}


//////////////////////////////////////////
   
int main(){

	 vector<int> arr = {64, 25, 12, 22, 11};

    cout << "Original array: ";
    printArray(arr);

    selectionSort(arr);

    cout << "Sorted array: ";
    printArray(arr);

return 0;
}
