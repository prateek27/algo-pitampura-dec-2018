#include<iostream>
using namespace std;


//Top Down DP
int fib(int n,int *dp){

	if(n==0||n==1){
		return n;
	}
	if(dp[n]!=-1){
		return dp[n];
	}

	//Rec Case
	dp[n] =  fib(n-1)+fib(n-2);
	return dp[n];
}