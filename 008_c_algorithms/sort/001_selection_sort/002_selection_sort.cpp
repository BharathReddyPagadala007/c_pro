#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;





int main(){


vector<int>  arr= { 64,11,22,43,1,4,7,97,37,65};

cout<<"initial array vector\n"<< endl;
for(int i : arr){
cout<< i << "  " ;
}
cout << endl;
//////////////////////////////////////////////

cout << "first element   " << arr[0] << endl;

cout << "second element   "<< arr.at(1) <<endl;
cout << "first element   "<< arr.at(0) <<endl;
cout << "third element   "<< arr.at(2) <<endl;
//////////////////////////////////////////////

arr[2]=12;
cout << "third element   "<< arr.at(2) <<endl;
//////////////////////////////////////////////


for(int i : arr){
  cout << i << "  ";
}
cout<< endl;

//////////////////////////////////////////////


arr.push_back(99);

for(int num : arr){
 cout<< num << " ";

}
cout << endl;
//////////////////////////////////////////////


arr.pop_back();

for(int num: arr){
cout<< num << " ";
}
cout<< endl;
//////////////////////////////////////////////



arr.insert(arr.begin()+2,100);
for(int num : arr){
cout << num << " ";
}
cout<<endl;

//////////////////////////////////////////////

arr.erase(arr.begin() +2);
for(int num :  arr){

cout<< num << " ";
}
cout<< endl;
//////////////////////////////////////////////
/*

//arr.clear();
for(int num: arr){

cout<< num << " ";
}
cout<< endl;

cout << "After clearing, size: " << arr.size() << endl;
cout << "Is vector empty? " << (arr.empty() ? "Yes" : "No") << endl;

*/
///////////////////////////////////

//arr.resize(5);

for(int num: arr){
cout<<num << " ";
}
cout<< endl;
///////////////////////////////////





sort(arr.begin(),arr.end());

for(int num : arr){
cout<<num << " ";
}
cout<< endl;


//////////////////////////////////////////sort desc

sort(arr.rbegin(),arr.rend());

for(int num : arr){
cout<<num << " ";
}
cout<< endl;


//////////////////////////////////////////sort desc


auto iter=find(arr.begin(),arr.end(),22);

if(iter!=arr.end()){cout<< iter-arr.begin()<< " ";}
else{
	cout<< "not foun"<< endl;
}



return 0;
}
