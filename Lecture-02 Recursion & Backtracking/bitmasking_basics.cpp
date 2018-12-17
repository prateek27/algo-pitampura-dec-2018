#include<iostream>
using namespace std;

int getLastBit(int n){
	return (n&1);
}
int getIthBit(int n,int p){
	return (n&(1<<p))>0?1:0;
}	
void setIthBit(int &n,int p){
	n = (n|(1<<p));
}

int main(){
	//Bitwise Operators?
	// &, |, ~, <<, >>
	// Fast!

	int n;
	cin>>n;
	cout<<"last bit "<<getLastBit(n)<<endl;

	cout<<"third last bit"<<getIthBit(n,3)<<endl;

	setIthBit(n,3);
	cout<<"After setting third last bit"<<n;



	return 0;
}