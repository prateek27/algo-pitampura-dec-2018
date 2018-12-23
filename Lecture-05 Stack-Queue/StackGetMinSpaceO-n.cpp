#include <iostream>
#include <vector>
using namespace std;

class Stack {
private:
	vector<int> gen;
	vector<int> min;
public:
	bool isEmpty() {
		return gen.size() == 0 and min.size() == 0;
	}
	void push(int x) {
		if(min.size() == 0 and gen.size() == 0) {
			gen.push_back(x);
			min.push_back(x);
			return;
		}

		gen.push_back(x);
		if(min[min.size()-1] >= x) {
			min.push_back(x);
		}
		return;
	}
	int genTop() {
		return gen[gen.size()-1];
	}
	int minTop() {
		return min[min.size()-1];
	}
	void pop() {
		if(isEmpty()) {
			cout<<"Stack is Empty!"<<endl;
			return;
		}
		if(minTop() == genTop()) {
			min.pop_back();
		}
		gen.pop_back();
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
