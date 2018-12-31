#include<iostream>
#include<unordered_map>
#include<list>
#include<cstring>
using namespace std;

class Graph{
	int V;
	unordered_map<string,list<pair<string,int> > > m;
public:
	Graph(int v){
		V = v;
	}

	void addEdge(string src,string dest,int wt,bool bidir=true){
		m[src].push_back(make_pair(dest,wt));
		if(bidir){
			m[dest].push_back(make_pair(src,wt));
		}
	}
	void print(){

		for(auto p:m){
			string src = p.first;
			auto cities = p.second;

			cout<<src<<"-->";
			for(auto city:cities){
				cout<<"("<<city.first<<","<<city.second<<")";
			}
			cout<<endl;
		}
	}
};

int main(){

	Graph g(5);
	g.addEdge("Delhi","Amritsar",1);
	g.addEdge("Delhi","Jaipur",2);
	g.addEdge("Delhi","Bhopal",6);
	g.addEdge("Delhi","Lucknow",3);
	g.addEdge("Jaipur","Amritsar",5);
	g.addEdge("Jaipur","Bhopal",4);
	g.print();


	return 0;
}