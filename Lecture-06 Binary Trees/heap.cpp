#include<iostream>
#include<vector>
using namespace std;

class Heap{
	//Assuming Min Heap
	vector<int> v;

	void heapify(int i){
		
		int left = 2*i;
		int right = left + 1;

		int min_i = i;

		if(left<v.size() and v[left] <v[min_i]){
			min_i = left;
		}
		if(right<v.size() and v[right] <v[min_i]){
			min_i = right;
		}

		if(min_i!=i){
			//kind of base case + rec case
			swap(v[min_i],v[i]);
			heapify(min_i);
		}
	}


public:

	Heap(int ds=1000){
		v.reserve(ds);
		v.push_back(-1); //block the 0th position

	}

	void push(int data){
		//insert a new element
		v.push_back(data);
		int idx = v.size()-1;

		int parent = idx/2;

		while(idx>1 and v[idx]<v[parent]){
			swap(v[idx],v[parent]);
			idx = parent;
			parent = parent/2;
		}
	}
	int top(){
		//get min element
		return v[1];

	}
	void pop(){
		//Remove min element
		int last_idx = v.size()-1;
		swap(v[last_idx],v[1]);
		v.pop_back();
		heapify(1);
	}
	bool empty(){
		return v.size()==1;
	}

};


int main(){

	Heap h;

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



}