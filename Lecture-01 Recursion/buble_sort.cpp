#include<iostream>
using namespace std;

void bubleSort(int *a,int n){

	if(n==1){
		return;
	}

	for(int i=0;i<n-1;i++){
		if(a[i]>a[i+1]){
			swap(a[i],a[i+1]);
		}
	}
	bubleSort(a,n-1);

}

void bubleSort2(int *a,int n,int i){

	if(n==1){
		return;
	}
	if(i==n-1){
		bubleSort2(a,n-1,0);
		return;
	}
	if(a[i]>a[i+1]){
			swap(a[i],a[i+1]);
	}
	bubleSort2(a,n,i+1);


}

int main(){

	int a[] = {5,4,3,2,1};

	int n  = sizeof(a)/sizeof(int);

	bubleSort2(a,n,0);
	for(int i=0;i<n;i++){
		cout<<a[i]<<" "<<endl;
	}


	return 0;
}