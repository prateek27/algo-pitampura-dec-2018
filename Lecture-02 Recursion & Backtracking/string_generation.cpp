#include<iostream>
using namespace std;

void generateString(char *in,char *out,int i,int j){
	//Base Case
	if(in[i]=='\0'){\
		out[j] = '\0';
		cout<<out<<endl;
		return;
	}
	//Rec Case
	//One Char at a time
	int digit = in[i] - '0';
	char ch = digit + 'A'-1;
	out[j] = ch;
	generateString(in,out,i+1,j+1);
	//Two char at a time
	if(in[i+1]!='\0'){
		int secondDigit = in[i+1]-'0';
		int no = digit*10 + secondDigit;
		if(no<=26){
			ch = no + 'A'-1;
			out[j] = ch;
			generateString(in,out,i+2,j+1);
		}
	
	}
}

int main(){

	char a[100];
	cin>>a;
	char out[100];

	generateString(a,out,0,0);




}