#include<iostream>
using namespace std;


char digits[][10] = {
	"zero",
	"one",
	"two",
	"three",
	"four",
	"five",
	"six",
	"seven",
	"eight",
	"nine"
};

void printString(int n){
		if(n==0){
			return;
		}
		int d = n%10;
		printString(n/10);
		cout<<digits[d]<<" ";
}

int main(){
		int n;
		cin>>n;
		printString(n);
}