#include<iostream>
using namespace std; 

int dp[10000] = {0};

int minCoins(int n,int *coins,int m){

	if(n==0){
		return 0;
	}
	if(dp[n]!=0){
		return dp[n];
	}
	//Rec Case
	int ans = INT_MAX;

	for(int i=0;i<m;i++){

		if(coins[i]<=n){
			int subProb = minCoins(n-coins[i],coins,m);
			ans = min(ans,subProb+1);
		}
		
	}
	return dp[n]=ans;
}
//Bottom Up 
int minCoinsBottomUp(int n,int *coins,int m){
	//iterative

	int b[1000] ={0};
	b[0] = 0;

	for(int j=1;j<=n;j++){

		//Pick each type of coins
		int ans = INT_MAX;
		for(int i=0;i<m;i++){
		
			if(j>=coins[i]){
				int subProb = b[j-coins[i]];
				ans = min(subProb+1,ans);
			}
		}
		b[j] = ans;

	} 
	return b[n];


}





int main(){

	int N;
	cin>>N;
	int coins[] = {1,7,10};
	int m = 3;

	cout<<minCoins(N,coins,m)<<endl;
	cout<<minCoinsBottomUp(N,coins,m)<<endl;


	return 0;
}