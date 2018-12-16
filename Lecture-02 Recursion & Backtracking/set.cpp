#include<iostream>
#include<set>
using namespace std;

int main(){


	set<int> s;

	s.insert(1);
	s.insert(1);
	s.insert(5);
	s.insert(0);
	s.insert(2);


	for(int element:s){
		cout<<element<<",";
	}

	return 0;
}