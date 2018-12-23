#include <iostream>
using namespace std;

void generateParenthesis(int n, string str, int open, int close) {
	if(close >= n) { //base case
		cout<<str<<endl;
		return;
	}
	if(open < n) {
		generateParenthesis(n, str+'(', open + 1, close);
	}
	if(close < open) {
		generateParenthesis(n, str+')', open, close+1);
	}
	return ;

}
int main(int argc, char const *argv[])
{
	generateParenthesis(4, "", 0, 0);
	return 0;
}
