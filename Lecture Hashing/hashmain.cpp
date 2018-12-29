#include<iostream>
#include "hashtable.h"
using namespace std;


int main(){

	Hashtable h;
	h.insert("Mango",100);
	h.insert("Banana",20);
	h.insert("MangoShake",150);
	h.insert("pineapple",90);
	h.insert("Kiwi",120);

	//Find price of kiwi
	cout<<h.search("Kiwi")<<endl;

	

	h["Papaya"] = 30; //insertion -> sq brackets
	h["Papaya"] += 50; //update
	h["Papaya"] *= 10; //update
	cout<<h["Papaya"]; //lookup/search


	h.print();
	


	return 0;
}