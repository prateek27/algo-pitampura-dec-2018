#include<iostream>
using namespace std;

bool isSorted(int *a,int n){
	if(n==1){
		return true;
	}

	//Recursive Case
	if(a[0]<a[1] and isSorted(a+1,n-1)){
		return true;
	}
	return false;

}

int main(){

	int a[] = {1,4,5,6,7};
	if(isSorted(a,5)){
		cout<<"Yes!";
	}
	else{
		cout<<"No!";
	}

	return 0;
}