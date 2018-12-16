#include<iostream>
using namespace std;

int merge(int *a,int s,int e){

	int mid = (s+e)/2;
	int i = s;
	int j = (mid+1);
	int k = s;
	int temp[10000];

	int cnt = 0;

	while(i<=mid and  j<=e){
		if(a[i]<=a[j]){
			temp[k++] = a[i++];
		}
		else{
			temp[k++] = a[j++];
			cnt += mid - i + 1;
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
	return cnt;

}

int mergeSort(int *a,int s,int e){
	//Base Case
	if(s>=e){
		return 0;
	}
	//Recursive Case
	int mid = (s+e)/2;
	int x = mergeSort(a,s,mid);
	int y = mergeSort(a,mid+1,e);
	int z = merge(a,s,e); //Cross Inversions
	return x+y+z;
}

//Merge Sort
int main(){

	int a[] = {1,5,2,6,3,0};
	int n = sizeof(a)/sizeof(int);
	cout<<"Inversions "<<mergeSort(a,0,n-1)<<endl;

	for(int i=0;i<n;i++){
		cout<<a[i]<<" "<<endl;
	}




	return 0;
}