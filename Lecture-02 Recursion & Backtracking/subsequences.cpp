#include<iostream>
#include<set>
#include<cstring>
using namespace std;


void subsequences(char *in,char *out,int i,int j,set<string> &s){
	//Base Case
	if(in[i]=='\0'){
		out[j] = '\0';
		
		string temp(out); //Create a string object
		s.insert(temp); //insert into set s 

		return;
	}
	//Rec Case
	out[j] = in[i];
	subsequences(in,out,i+1,j+1,s);
	subsequences(in,out,i+1,j,s);

}

int main(){

	char a[100];
	cin>>a;

	char out[100];
	set<string> s;
	subsequences(a,out,0,0,s);

	for(string k:s){
		cout<<k<<endl;
	}

	return 0;
}