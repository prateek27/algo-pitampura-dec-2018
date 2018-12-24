#include<iostream>
#include<queue>
using namespace std;


class Compare{
public:
	bool operator()(int a,int b){
		return a>b;
	}
};	


int main(){

	priority_queue<int> h_max; //max heap
	priority_queue<int,vector<int>, greater<int> > h_min; // min_heap
	priority_queue<int,vector<int>, Compare > h; // user_defined

	//priority_queue<Person,vector<Person>, PersonCompare > h; // user_defined
	

	int d;
	cin>>d;
	while(d!=-1){
		h.push(d);
		cin>>d;
	}
	while(!h.empty()){
		cout<<h.top()<<endl;
		h.pop();
	}



	return 0;
}