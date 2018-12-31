#include<iostream>
#include<algorithm>
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

	//search(a,a+n,key) -->linear search
	//binary_search(a,a+n,key) -->boolean present or not
	//lower_bound(a,a+n,key) -->same key first occ
	//upper_bound(a,a+n,key) -->just bigger first occ

	int first_occ = lower_bound(a,a+n,3) - a; 
	cout<<first_occ <<endl;


	int next_occ = upper_bound(a,a+n,3) - a; 
	cout<< next_occ <<endl;

	return 0;
}