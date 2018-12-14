#include<iostream>
using namespace std;


int fastpower(int a,int n){

	if(n==0){
		return 1;
	}

	//Assumption-2
	int smallPower = fastpower(a,n/2);
	smallPower *= smallPower;

	if(n%2==1){
		return a*smallPower;
	}
	return smallPower;
}

int main(){

		int a,n;
		cin>>a>>n;
		cout<<fastpower(a,n)<<endl;

}