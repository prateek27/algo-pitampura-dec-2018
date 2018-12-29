#include<iostream>
#include<cstring>
using namespace std;

class Node{
public:
	string key;
	int value;
	Node*next;

	Node(string k,int v){
		key = k;
		value  = v;
		next = NULL;
	}
	~Node(){
		if(next!=NULL){
			delete next;
		}
	}
};


class Hashtable{
	Node**table;
	int cs; //current size
	int ts; //table size

	int hashFn(string key){

		int idx = 0;
		int p = 1;

		//formula + Step wise modulo to avoid overflow
		for(int i=0;i<key.length();i++){
			idx += p*key[i]%ts;
			idx %= ts;
			p = (p*37)%ts;
		}
		//(A+B+C)%m = (A%m + B%m +C%m)%m

		return idx;
	}
	void resize(){
		Node**oldTable = table;
		table = new Node*[2*ts];
		cs = 0;
		//Init the new table
		for(int i=0;i<2*ts;i++){
			table[i] = NULL;
		}

		int oldTs = ts;
		ts = 2*ts;
		//Iterate over old table and insert elements into new table
		for(int i=0;i<oldTs;i++){
			Node*temp = oldTable[i];
			while(temp!=NULL){
				insert(temp->key,temp->value);
				temp = temp->next;
			}
			delete oldTable[i];
		}
		delete [] oldTable;

	}

public:
	Hashtable(int ds=7){
		ts = ds;
		table = new Node*[ts];
		//Create and Init Table
		for(int i=0;i<ts;i++){
			table[i] = NULL;
		}
	}
	void insert(string key,int value){
		int idx = hashFn(key);
		Node* n = new Node(key,value);
		n->next = table[idx];
		table[idx] = n;
		cs++;

		float load_factor = cs/float(ts);
		if(load_factor>0.7){
			resize();
		}
	}

	int search(string key){

		int idx= hashFn(key);
		Node*temp = table[idx];
		while(temp!=NULL){
			if(temp->key==key){
				return temp->value;
			}
			temp = temp->next;
		}
		return -1;
	}
	int& operator[](string key){
		int f = search(key);
		if(f==-1){
			insert(key,0);
		}
		int idx= hashFn(key);
		Node*temp = table[idx];
		while(temp!=NULL){
			if(temp->key==key){
				return temp->value;
			}
			temp = temp->next;
		}
	}


	void print(){

		for(int i=0;i<ts;i++){
			cout<<"Bucket "<<i<<"-->";
			Node*temp = table[i];

			while(temp!=NULL){
				cout<<temp->key<<",";
				temp = temp->next;
			}
			cout<<endl;
		}
	}
	void remove(string key){
		//.....HW

	}
};