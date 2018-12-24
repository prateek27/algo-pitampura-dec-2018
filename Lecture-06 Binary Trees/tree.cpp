#include<iostream>
#include<queue>
using namespace std;

//node class
class node{
public:
	int data;
	node*left;
	node*right;

	node(int d):data(d),left(NULL),right(NULL){}
};

node* build(){
	int d;
	cin>>d; 

	//base case
	if(d==-1){
		return NULL;
	}
	//rec case
	node *root = new node(d);
	root->left = build();
	root->right = build();
	return root;
}
//preorder
void print(node*root){
	if(root==NULL){
		return;
	}
	cout<<root->data<<" ";
	print(root->left);
	print(root->right);

}
//inoroder
void print_in(node*root){
	if(root==NULL){
		return;
	}
	print_in(root->left);
	cout<<root->data<<" ";	
	print_in(root->right);

}
//postorder
void print_post(node*root){
	if(root==NULL){
		return;
	}
	print_post(root->left);
	print_post(root->right);
	cout<<root->data<<" ";

}

int count(node*root){
		if(root==NULL){
			return 0;
		}
		return 1 + count(root->left) + count(root->right);
}
int height(node*root){
	if(root==NULL){
		return 0;
	}
	return 1 + max(height(root->left),height(root->right));
}

void printAtLevelK(node*root,int k){
		//Base Case
		if(root==NULL or k<0){
			return;
		}
		if(k==0){
			cout<<root->data<<" ";
			return;
		}
		printAtLevelK(root->left,k-1);
		printAtLevelK(root->right,k-1);
}

void printAllLevels(node*root){
	int H = height(root);
	for(int i=0;i<H;i++){
		printAtLevelK(root,i);
		cout<<endl;
	}

}
// Iteratively! ---> Breadth First Search(BFS)
void printBFS(node*root){

		queue<node*> q;
		q.push(root);
		q.push(NULL);

		while(!q.empty()){
			node* f = q.front();

			if(f==NULL){
				cout<<endl;
				q.pop();
				if(!q.empty()){
					q.push(NULL);
				}
				continue;
			}


			cout<<f->data<<" ";
			q.pop();

			if(f->left){
				q.push(f->left);
			}
			if(f->right){
				q.push(f->right);
			}
		}
}

node* buildusingBFS(){

	node*root = NULL;
	queue<node*> q;

	int d;
	//cout<<"Enter root data";
	cin>>d;
	root = new node(d);

	q.push(root);

	while(!q.empty()){

		node*f = q.front();
		//cout<<"Enter children of "<<f->data<<endl;
		int c1,c2;
		q.pop();

		cin>>c1>>c2;
		if(c1!=-1){
			f->left = new node(c1);
			q.push(f->left);
		}
		if(c2!=-1){
			f->right = new node(c2);
			q.push(f->right);
		}
	}
	return root;
}

void mirror(node*root){
	if(root==NULL){
		return;
	}
	swap(root->left,root->right);
	mirror(root->left);
	mirror(root->right);
}

//Sum of all nodes
int sumOfAllNodes(node*root){
	if(root==NULL){
		return 0;
	}
	root->data += sumOfAllNodes(root->left) + sumOfAllNodes(root->right);
	return root->data;
}

//Sum of all nodes 
int sumOfAllNodes2(node*root){
	if(root==NULL){
		return 0;
	}
	if(root->left==NULL and root->right==NULL){
		return root->data;
	}

	int temp = root->data;
	root->data = sumOfAllNodes2(root->left) + sumOfAllNodes2(root->right);
	return temp + root->data;
}

int diameter(node*root){
	if(root==NULL){
		return 0;
	}
	//Rec Case
	int op1 = height(root->left) + height(root->right);
	int op2 = max(diameter(root->left),diameter(root->right));
	return max(op1,op2);
}

pair<int,int> diameterFast(node*root){
	pair<int,int> p;
	if(root==NULL){
			p.first = p.second = 0;
			return p;
	}
	//Rec Case
	pair<int,int> left, right;
	left = diameterFast(root->left);
	right = diameterFast(root->right);

	p.first = max(left.first,right.first)  + 1;

	int op1 = left.first + right.first;
	int op2 = max(left.second,right.second);

	p.second = max(op1,op2);
	return p;
}


class Pair{
public:
	int height;
	int diameter;
};

Pair diameterF2(node*root){
	Pair p;
	if(root==NULL){
		p.diameter = p.height = 0;
		return p;
	}
	Pair PairLeft,PairRight;
	PairLeft = diameterF2(root->left);
	PairRight = diameterF2(root->right);

	p.height = max(PairLeft.height,PairRight.height	)+1;

	int op1 = PairRight.height + PairLeft.height;
	int op2 = max(PairLeft.diameter,PairRight.diameter);
	p.diameter = max(op1,op2);
	return p;
}

class PairHB{
public:
	int height;
	bool balance;
};

PairHB heightBalanced(node*root){
	PairHB p;
	if(root==NULL){
		p.height =0;
		p.balance = true;
	}
	//Otherwise!
	PairHB leftAns,rightAns;
	leftAns = heightBalanced(root->left);
	rightAns = heightBalanced(root->right);

	int h1 = leftAns.height;
	int h2 = rightAns.height;

	p.height = max(h1,h2) + 1;
	if(abs(h1-h2)<=1 and leftAns.balance and rightAns.balance){
		p.balance = true;
		return p;
	}
	p.balance = false;
	return p;

}


int main(){

	node*root=NULL;
	//root = buildusingBFS();
	root = build();

	/*
	print(root);
	cout<<endl;
	print_in(root);
	cout<<endl;
	print_post(root);
	cout<<endl;
	*/
	cout<<"Nodes "<<count(root)<<endl;
	cout<<"Height "<<height(root)<<endl;
	//printAllLevels(root);
	printBFS(root);
	cout<<"Diam "<<diameterF2(root).diameter<<endl;

	
	return 0;
}