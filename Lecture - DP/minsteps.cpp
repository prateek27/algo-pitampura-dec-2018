#include<iostream>
using namespace std;
//Top Downn
int steps(int n,int *dp){
	if(n==1){
		return 0;
	}
	//---------------Every DP Code
	if(dp[n]!=0){
		return dp[n];
	}

	//Base Case
	int x,y,z,ans;
	x = y = z = ans = INT_MAX;

	x = steps(n-1,dp) + 1;

	if(n%2==0){
		y = steps(n/2,dp) + 1;
	}

	if(n%3==0){
		z = steps(n/3,dp) + 1;  
	}

	ans = min(x,min(y,z));
	return dp[n] = ans;
}

int main(){

	int n;
	cin>>n;
	int dp[1000] ={0};

	cout<<steps(n)<<endl;

	return 0;
}