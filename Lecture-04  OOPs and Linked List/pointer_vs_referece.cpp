#include<iostream>
using namespace std;


int& inc(int &y){
	y = y+1;
	//return i;
	return y;
}


int main(){

	int x = 10;
	inc(x);
	cout<<x<<endl;
	int &z =x;
	inc(z) = 15;
	cout<<x<<endl;

	return 0;
}