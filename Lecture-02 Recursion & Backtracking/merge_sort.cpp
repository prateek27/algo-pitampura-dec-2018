#include<iostream>
using namespace std;

void merge(int *a,int s,int e){

	int mid = (s+e)/2;
	int i = s;
	int j = (mid+1);
	int k = s;
	int temp[10000];

	while(i<=mid and  j<=e){
		if(a[i]<=a[j]){
			temp[k++] = a[i++];
		}
		else{
			temp[k++] = a[j++];
		}
	}
	//What after?
	while(i<=mid){
		temp[k++] = a[i++];
	}
	while(j<=e){
		temp[k++] = a[j++];
	}
	//Anything else?
	//Copy elements back to a
	for(int i=s;i<=e;i++){
		a[i] = temp[i];
	}
	return;

}

void mergeSort(int *a,int s,int e){
	//Base Case
	if(s>=e){
		return;
	}
	//Recursive Case
	int mid = (s+e)/2;
	mergeSort(a,s,mid);
	mergeSort(a,mid+1,e);
	merge(a,s,e);
	return;
}

//Merge Sort
int main(){

	int a[] = {1,5,3,6,2,7};
	int n = sizeof(a)/sizeof(int);
	mergeSort(a,0,n-1);

	for(int i=0;i<n;i++){
		cout<<a[i]<<" "<<endl;
	}




	return 0;
}