#include <iostream>
#include <stack>
using namespace std;
int main(int argc, char const *argv[])
{
	stack<int> st;
	st.push(10);
	st.push(20);
	st.push(30);
	cout<<st.size()<<endl;

	while(not st.empty()) {
		cout<<st.top()<<" ";
		st.pop();
	}
	cout<<endl;
	return 0;
}
