#include <iostream>
#include <vector>
using namespace std;

class Stack {
private:
	vector<int> v;
public:
	bool isEmpty() {
		return v.size() == 0;
	}
	void push(int x) {
		v.push_back(x);
		return;
	}
	void pop() {
		if(isEmpty()) {
			cout<<"Stack is Empty!"<<endl;
			return;
		}
		v.pop_back();
	}
	int top() {
		return v[v.size()-1];
	}

};

int main(int argc, char const *argv[])
{
	/* code */
	Stack s;
	s.push(1);
	s.push(2);
	s.push(20);
	while(not s.isEmpty()) {
		cout<<s.top()<<endl;
		s.pop();
	}
	return 0;
}
