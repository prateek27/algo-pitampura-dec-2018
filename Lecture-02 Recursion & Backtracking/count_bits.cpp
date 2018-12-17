#include<iostream>
using namespace std;

int cntBits(int n){

	int cnt =0;
	while(n>0){
		cnt += (n&1);
		n = n>>1;
	}
	return cnt;
}

int cntBits2(int n){
	int cnt=0;
	while(n){
		cnt++;
		n = n&(n-1);
	}
	return cnt;
}

int cntBits3(int n){
	int cnt=0;
	while(n){
		int p = n&(-n);
		n = n - p;
		cnt++;
	}
	return cnt;
}

int main(){
	//Bitwise Operators?
	// &, |, ~, <<, >>
	// Fast!

	int n;
	cin>>n;
	cout<<cntBits(n)<<endl; // O(No of bits = 32 or 64)
	cout<<cntBits2(n)<<endl; // O(No of set bits)	
	cout<<cntBits3(n)<<endl; // O(No of set bits)	
	
	cout<<__builtin_popcount(n)<<endl; //Faster

	return 0;
}