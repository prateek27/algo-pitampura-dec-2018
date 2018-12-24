#include <iostream>
#include <stack>
using namespace std;

bool redundantParenthesis(string str) {
	stack<char> s;
	for(int i = 0; i < str.length(); i++) {
		char curr = str[i];
		if(curr != ')') {
			s.push(curr);
		} else if(curr == ')') {
			if(s.empty()) {
				return true;
			}
			if(s.top()=='(') {
				return true;
			}
			while(s.top()!='(') {
				s.pop();
			}
			s.pop();
		}
	}
	return false;
}

int main(int argc, char const *argv[])
{
	string str;
	cin>>str;
	if(redundantParenthesis(str)) {
		cout<<"Yes"; 
	} else {
		cout<<"No";
	}
	
	return 0;
}
