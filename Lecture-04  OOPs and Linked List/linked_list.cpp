#include<iostream>
using namespace std;

class node{
public:
	int data;
	node* next;

	node(int d){
		data = d;
		next = NULL;
	}
};
/*
class LinkedList{

	node*head;
	node*tail;
public:
	void add(___)
}
*/
void insertAtHead(node*&head,int data){

	if(head==NULL){
		head = new node(data);
		return;
	}
	node*n = new node(data);
	n->next = head;
	head = n;
}

void insertInTheMiddle(node*&head,int data,int p){
	if(p==0){
		insertAtHead(head,data);
	}
	else{
		node*temp = head;
		for(int i=1;i<=p-1;i++){
			temp = temp->next;
		}
		node*n = new node(data);
		n->next = temp->next;
		temp->next = n;

	}
}

void print(node*head){
	while(head!=NULL){
		cout<<head->data<<"->";
		head = head->next;
	}
	cout<<endl;
}
void deleteAtHead(node*&head){
	if(head!=NULL){
		node*temp = head;
		head = head->next;
		delete temp;
	}
}
//void deleteInTheMiddle(node*&head,int data)

ostream&operator<<(ostream&a,node*head){
	print(head);
	return a;
}

istream&operator>>(istream&a,node*&head){
	int d;
	cin>>d;
	while(d!=-1){
		insertAtHead(head,d);
		cin>>d;
	}
	return a;
}
bool search(node*head,int key){
	//Base Case
	if(head==NULL){
		return false;
	}

	//Rec Case
	if(head->data==key){
		return true;
	}
	return search(head->next,key);
}
void reverse(node*&head){
	node*p = NULL;
	node*c = head;
	node*n;

	while(c!=NULL){
		//save the next node
		n = c->next;
		//udpate the current node
		c->next = p;
		//move c and p one step ahead
		p = c;
		c = n;
	}
	head = p;
}
node* recReverse(node *head){
	if(head->next==NULL){
		return head;
	}
	//Rec Case
	node*chotaHead = recReverse(head->next);
	head->next->next = head;
	head->next = NULL;
	return chotaHead;
}
node* midPoint(node*head){

	node*slow = head;
	node*fast = head->next;

	while(fast!=NULL and fast->next!=NULL){
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}

//Forward Declare
node*merge(node*a,node*b);

node* mergeSort(node*l){
	if(l==NULL or l->next==NULL){
		return l;
	}

	node*mid =  midPoint(l);
	node*a = l;
	node*b = mid->next;
	mid->next = NULL;

	a = mergeSort(a);
	b = mergeSort(b);

	return merge(a,b);


}

node* merge(node*a,node*b){
	if(a==NULL){
		return b;
	}
	if(b==NULL){
		return a;
	}

	node*c;
	if(a->data < b->data){
		c = a;
		c->next = merge(a->next,b);
	}
	else{
		c=b;
		c->next = merge(a,b->next);
	}
	return c;

}


int main(){
	node*head = NULL;
	cin>>head;
	head = mergeSort(head);
	cout<<head;

	return 0;
}