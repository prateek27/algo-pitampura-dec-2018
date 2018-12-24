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

node* insertInBST(node*root,int data){
	if(root==NULL){
		return new node(data);
	}
	if(data<root->data){
		root->left = insertInBST(root->left,data);
	}
	else{
		root->right = insertInBST(root->right,data);
	}
	return root;
}

node* buildBST(){
	node*root = NULL;
	int d;
	cin>>d;
	while(d!=-1){
		root = insertInBST(root,d);
		cin>>d;
	}
	return root;
}

istream& operator>>(istream &a,node*&root){
	root = buildBST();
	return a;
}

bool search(node* root,int key){
	if(root==NULL){
		return false;
	}
	if(root->data==key){
		return true;
	}
	if(root->data < key){
		return search(root->right,key);
	}
	return search(root->left,key);
}

node* removeNode(node*root,int key){

	if(root==NULL){
		return NULL;
	}
	if(root->data < key){
		root->right = removeNode(root->right,key);
		return root;
	}
	else if(root->data >key){
		root->left = removeNode(root->left,key);
		return root;
	}
	else{
		//Equal
		//0 child
		if(root->left==NULL and root->right==NULL){
			delete root;
			return NULL;
		}


		//1 child
		if(root->left!=NULL and root->right==NULL){
			node*temp = root->left;
			delete root;
			return temp;
		}
		if(root->left==NULL and root->right!=NULL){
			node*temp = root->right;
			delete root;
			return temp;
		}
		// 2 children
		node*temp = root->right;
		while(temp->left!=NULL){
			temp = temp->left;
		}
		root->data = temp->data;
		root->right = removeNode(root->right,root->data);
		return root;
	}

}
node* arrayToBST(int *arr,int s,int e){
	//Base Case
	if(s>e){
		return NULL;
	}

	int mid = (s+e)/2;
	node*root = new node(arr[mid]);
	root->left = arrayToBST(arr,s,mid-1);
	root->right = arrayToBST(arr,mid+1,e);
	return root;
}

class LinkedList{
public:
	node*head;
	node*tail;
};

LinkedList tree2LL(node*root){
	//Base Case
	LinkedList l;
	if(root==NULL){
		l.head = l.tail = NULL;
		return l;
	}
	if(root->left==NULL and root->right==NULL){
		l.head = l.tail = root;
		return l;
	}
	// one of the left or right is null
	if(root->left==NULL and root->right!=NULL){
		LinkedList rightLL = tree2LL(root->right);
		root->right = rightLL.head;
		l.head = root;
		l.tail = rightLL.tail;
		return l;
	}
	if(root->left!=NULL and root->right==NULL){
		LinkedList leftLL = tree2LL(root->left);
		leftLL.tail->right = root;
		l.head = leftLL.head;
		l.tail = root;
		return l;
	}
	//both are not null
	LinkedList leftLL,rightLL;
	leftLL = tree2LL(root->left); //Left 
	rightLL = tree2LL(root->right);//Right
	leftLL.tail->right = root; //Root -->Postorder
	root->right = rightLL.head;
	l.head = leftLL.head;
	l.tail = rightLL.tail;
	return l;

}





int main(){

	
	node*root = NULL;
	cin>>root;

	print(root);
	cout<<endl;
	print_in(root);
	cout<<endl;
	print_post(root);
	cout<<endl;

	LinkedList l = tree2LL(root);
	node*temp = l.head;
	while(temp!=NULL){
		cout<<temp->data<<"--> ";
		temp = temp->right;
	}

	
	/*
	cout<<"Nodes "<<count(root)<<endl;
	cout<<"Height "<<height(root)<<endl;
	//printAllLevels(root);
	printBFS(root);
	cout<<"Diam "<<diameterF2(root).diameter<<endl;
	*/
	
	return 0;
}