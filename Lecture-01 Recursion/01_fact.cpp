#include<iostream>
using namespace std;

int fact(int n){
	//Base Case
	if(n==0){
		return 1;
	}
	//Recursive Case
	int ans = n*fact(n-1);
	return ans;

}

int fib(int n){
	if(n==0 or n==1){
		return n;
	}
	return fib(n-1) + fib(n-2);
}


int main(){
	cout<<fib(6)<<endl;

	return 0;
}