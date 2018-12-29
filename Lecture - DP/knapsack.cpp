#include<iostream>
using namespace std;

int dp[100][100] = {0};

int knapsack(int *p,int *wts,int c,int n){
	if(n==0 or c==0){
		return 0;
	}
	if(dp[n][c]!=0){
		return dp[n][c];
	}
	//Ignore
	int ans = knapsack(p,wts,c,n-1);
	//Include
	if(c-wts[n-1]>=0){
		ans = max(ans,knapsack(p,wts,c-wts[n-1],n) + p[n-1]);
	}
	return dp[n][c]=ans;
}

//bottom up
int knapsack(int *p,int *wts,int c,int n){
	//Try krna



}



int main(){

	int prices[] = {14,12,5};
	int wts[]= {3,2,6};
	int n = 3;
	cout<<knapsack(prices,wts,7,n)<<endl;





	return 0;
}