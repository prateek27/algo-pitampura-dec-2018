#include<iostream>
#include<unordered_map>
#include<list>
#include<cstring>
#include<queue>
using namespace std;

class Graph{
	int V;
	unordered_map<string,list<string>> m;
public:
	Graph(int v){
		V = v;
	}

	void addEdge(string src,string dest,bool bidir=true){
		m[src].push_back(dest);
		if(bidir){
			m[dest].push_back(src);
		}
	}
	void print(){

		for(auto p:m){
			string src = p.first;
			auto cities = p.second;

			cout<<src<<"-->";
			for(auto city:cities){
				cout<<"("<<city<<")";
			}
			cout<<endl;
		}
	}

	void bfsTraversal(string src,string dest){

		queue<string> q;

		unordered_map<string,bool> visited;

		unordered_map<string,string> parent;
		unordered_map<string,int> distance;
		
		
		q.push(src);
		visited[src] = true;
		distance[src] = 0;
		parent[src]= src;
		
		while(!q.empty()){

			string city = q.front();
			cout<<city<<" - ";
			q.pop();

			//children of current node
			for(auto child:m[city]){
				if(!visited[child]){
					q.push(child);
					visited[child] = true;
					distance[child] = distance[city] + 1;
					parent[child] = city;
				}
			}
		}

		string temp= dest;
		cout<<endl;
		while(temp!=src){
			cout<<temp<<"<--";
			temp = parent[temp];
		}
		cout<<src<<endl;
		cout<<endl;
		cout<<"Dist of Dest is"<<distance[dest]<<endl;
	}
	void dfsHelper(string node,unordered_map<string,bool> &visited){
		//Visit the current node
		//mark it as visited
		// explore any unvisited child of that node --repeat
		cout<<node<<" ";
		visited[node] = true;

		for(auto child:m[node]){
			if(!visited[child]){
				dfsHelper(child,visited);
			}
		}
	}
	void dfsTraversal(string src){
		unordered_map<string,bool> visited;
		dfsHelper(src,visited);
	}

};

int main(){

	Graph g(5);
	g.addEdge("Delhi","Amritsar");
	g.addEdge("Delhi","Jaipur");
	g.addEdge("Delhi","Bhopal");
	g.addEdge("Delhi","Lucknow");
	g.addEdge("Jaipur","Amritsar");
	g.addEdge("Jaipur","Bhopal");
	g.addEdge("Mumbai","Bhopal");
	g.addEdge("Mumbai","Pune");
	//g.print();

	g.dfsTraversal("Delhi");
	cout<<endl<<"BFS";

	string d;
	cin>>d;
	cout<<endl;
	g.bfsTraversal("Delhi",d);
	return 0;
}