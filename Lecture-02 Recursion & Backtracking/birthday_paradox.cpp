#include<iostream>
using namespace std;


int main(){

	int cnt=0;
	
	float threshold;
	cin>>threshold;
	
	int num = 365;
	float denom = 365.0;
	float ans = 1;

	while(ans>=1-threshold){
		ans = ans*num/denom;
		num--;
		cnt++;

		cout<<"People "<<cnt<<"Prob "<<ans<<endl;
	}
	cout<<cnt<<endl;

	return 0;
}