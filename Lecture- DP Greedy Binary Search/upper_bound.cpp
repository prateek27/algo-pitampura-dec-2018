#include<iostream>
using namespace std;

int lowerBound(int *a,int n,int key){

	int s = 0;
	int e = n-1;

	int ans = -1;
	while(s<=e){
		int mid = (s+e)/2;

		if(a[mid]==key){
			ans = mid;
			e = mid-1;
		}
		else if(a[mid]>key){
			e = mid-1;
		}
		else{
			s = mid+1;
		}
	}
	return ans;
}


int main(){

	int a[] = {1,1,2,2,2,2,4,4,5,6,7};
	int n  = sizeof(a)/sizeof(int);

	int key;
	cin>>key;

	cout<<lowerBound(a,n,key)<<endl;

	return 0;
}