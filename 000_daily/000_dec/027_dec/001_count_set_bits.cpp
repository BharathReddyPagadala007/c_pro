//===========================================
//https://leetcode.com/problems/counting-bits/description/
//=============================================
#include<iostream>
#include<vector>
using namespace std;
class Solution{
public:
	//=====================================================
	vector<int> countBits(int n){

		vector<int> bits(n+1,0);

		for(int i=1; i<=n; i++){

			bits[i] = bits[i&(i-1)] + 1;
			//bits[i] = bits[i>>1] + (i&1);
		}

	return bits;
	}
	//=====================================================
};

int main(){

	int n;
	cout<<"enter n\n";
	cin>>n;


	 Solution obj;
	 vector<int> result = obj.countBits(n);

	 for(int i=0; i<result.size(); i++){
		 cout<< result[i] <<"  ";
	 }


return 0;
}
