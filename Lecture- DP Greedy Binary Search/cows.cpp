#include<iostream>
using namespace std;

bool cowsRakho(int stalls[],int n,int c,int min_sep){

	//Place the first cow in first stall
	int last_cow = stalls[0] ;
	int cnt = 1;

	//Go over remaining stalls,try to place c-1 cows
	for(int i=1;i<n;i++){
		if(stalls[i] - last_cow>=min_sep){
			last_cow = stalls[i];
			cnt++;

			if(cnt==c){
				return true;
			}
		}
	}
	return false;

}

int main(){
	//Problem : Aggresive Cows(Spoj.com)
	int stalls[] = {1,2,4,8,9};
	int n = 5;

	int cows;
	cin>>cows;

	//Binary Search
	int s = 0;
	int e = stalls[n-1] - stalls[0];
	int ans = 0;

	while(s<=e){
		int mid = (s+e)/2;

		//Find out if you can place cows at min_separation  mid 
		bool cowRakhPayeKya = cowsRakho(stalls,n,cows,mid);
		if(cowRakhPayeKya==true){
			ans = mid;
			s = mid + 1;
		}
		else{
			e = mid - 1;
		}
	}

	cout<<ans<<endl;


}