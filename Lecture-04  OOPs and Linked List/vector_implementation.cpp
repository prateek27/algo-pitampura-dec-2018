#include<iostream>
#include<vector>
using namespace std;


int main(){

	vector<int> v;
	v.reserve(100);
	for(int i=0;i<=5;i++){
		v.push_back(i*i);
	}

	//Print
	for(int i=0;i<v.size();i++){
		v[i] = 7; //Update
		cout<<v[i]<<" ";
	}
	//Print C++11
	for(int x:v){
		cout<<x<<endl;
	}

	cout<<endl;
	cout<<v.size()<<endl;
	cout<<v.capacity()<<endl;
	cout<<v.max_size()<<endl;

	return 0;
};