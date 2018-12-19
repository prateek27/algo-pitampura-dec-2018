#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

template<typename T>
class Vector{

	T *arr; //Pointer to array
	int cs;
	int capacity;

public:
	Vector(int ds=1){
		capacity = ds;
		arr = new T[capacity]; //Dynamic Memory Allocation -->Heap
		cs = 0;
	}
	Vector(const Vector<T> &X){
		cs = X.cs;
		capacity = X.get_capacity();

		//Deep Copy
		arr = new T[capacity];

		for(int i=0;i<cs;i++){
			arr[i]= X.arr[i];
		}
	}
	void operator=(const Vector<T> &X){
		cs = X.cs;
		capacity = X.get_capacity();

		//Deep Copy
		arr = new T[capacity];

		for(int i=0;i<cs;i++){
			arr[i]= X.arr[i];
		}
	}

	void push_back(const T data){
		if(cs==capacity){
			//Expand the current array
			T *oldArr = arr;
			arr = new T[capacity<<1];

			for(int i=0;i<capacity;i++){
				arr[i]= oldArr[i];
			}
			//Delete the old array
			delete [] oldArr;
			capacity = capacity<<1;
		}
		arr[cs] = data;
		cs++;
	}
	int size() const{
		return cs;
	}
	void pop_back(){
		if(cs>0){
			cs--;
		}
	}

	void set_capacity(int c){
		if(c>0){
			//Resize to capacity 
			capacity = c;
		}
	}
	int get_capacity() const{
		return capacity;
	}
	T at(int i) const{
		return arr[i];
	}
	//Unary -
	void operator-(){
		for(int i=0;i<cs;i++){
			arr[i] *= -1;
		}
	}
	//Binary +
	void operator+(const int no){
		for(int i=0;i<cs;i++){
			arr[i] += no;
		}
	}
	void operator()(const string name) const{
		cout<<name<<" having Fun!";
	}
	T& operator[](int i){
		return arr[i];
	}
	~Vector(){
		cout<<"Deleting Vector!"<<endl;
		if(arr!=NULL){
			delete [] arr;
			arr = NULL;
		}
	}
};
//Class k bahar
ostream& operator<<(ostream &a, Vector<int> &v){

	for(int i=0;i<v.size();i++){
		cout<<v[i]<<" , ";
	}
	cout<<endl;
	return a;
}
istream& operator>>(istream&b,Vector<int> &v){
	int n;
	cin>>n;

	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;
		v.push_back(temp);
	}

	return b;
}


int main(){

	Vector<int> v(10);
	cin>>v;

	//Vector<int> v2=v; //Copy COnstructor
	
	Vector<int> v2;
	v2 = v; //Copy Assignment Operator 


	v2[1] = 100;
	cout<<v<<endl;
	cout<<v2<<endl;


	/*	
	//v+3;
	v("Cody"); //Functional Object in C++ | Functor

	cout<<v;

	
	for(int i=0;i<v.size();i++){
		//cout<<v.at(i)<<" ";
		v[i]= 7;  
		cout<<v[i]<<",";
	}
	
	cout<<endl;
	cout<<v.size()<<endl;
	cout<<v.get_capacity()<<endl;
	*/
		
	//Dynamic Vector
	vector<int> *vptr = new vector<int>; 
	delete vptr;

	return 0;
}