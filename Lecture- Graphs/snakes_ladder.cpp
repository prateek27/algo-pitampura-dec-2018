#include<iostream>
#include<list>
#include<queue>
using namespace std;


class Graph{

	list<int> *l;
	int V;
public:
	Graph(int V){
		this->V = V+1;
		l = new list<int>[V+1];
	}
	void addEdge(int u,int v){
		l[u].push_back(v);
	}
	void bfs(int s){

		bool *visited = new bool[V]{0};
		int *dist = new int[V];
		queue<int> q;
		
		for(int i=0;i<V;i++){
			dist[i] = -1;
		}

		q.push(s);
		visited[s] = true;
		dist[s] = 0;

		while(!q.empty()){
			int f = q.front();
			q.pop();

			for(auto nbr_cell:l[f]){
				if(!visited[nbr_cell]){
					q.push(nbr_cell);
					visited[nbr_cell] = true;
					dist[nbr_cell] = dist[f] + 1;
				}
			}
		}

		for(int i=0;i<V;i++){
			cout<<"Cell "<<i<<" Dist "<<dist[i]<<endl;
		}
	}


};


int main(){

	Graph g(37);
    int board[50] = {0};
    board[2]= 13;
    board[5] = 2;
    board[9] = 18;
    board[18] = 11;
    board[17] = -13;
    board[20] = -14;
    board[24] = -8;
    board[25] = 10;
    board[32] = -2;
    board[34] = -22;


    for(int i=0;i<36;i++){
    	for(int dice=1;dice<=6;dice++){
    		int j = i + dice;
    		j+=board[j];

    		if(j<=36){
    			g.addEdge(i,j);
    		}
    	}
    }

    g.bfs(0);



	return 0;
}