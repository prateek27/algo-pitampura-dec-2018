#include<iostream>
#include<list>
#include<queue>
using namespace std;


class Graph{
    int V;
    ///Pointer to a dynamic Array of Linked Lists
    list <int> *l;

public:
    Graph(int v){
        V = v;
        l = new list<int>[V];
    }

    void addEdge(int u,int v,bool bidir=true){
        l[u].push_back(v);
        if(bidir){
            l[v].push_back(u);
        }
    }

    void printAdjList(){

        for(int i=0;i<V;i++){
            cout<<i<<"=>";
            /// for(list<int>::iterator it = l[i].begin();it!=l[i].end();it++) cout<< *it <<endl;
            /// for(vector<int>::iterator iv =

            for(auto j:l[i]){
                cout<<j<<",";
            }
            cout<<endl;
        }
    }

    void topologicalSort(){
        int*indegree = new int[V]{0};

        for(int i=0;i<V;i++){
            for(auto j:l[i]){
                indegree[j]++;
            }
        }
        queue<int> q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        ///Start removing nodes from the queue
        while(!q.empty()){
                int f = q.front();
                cout<<f<<" ";
                q.pop();

                for(int child:l[f]){
                    indegree[child]--;
                    if(indegree[child]==0){
                        q.push(child);
                    }
                }
        }
        cout<<endl;
    }
    int findParent(int i,int *parent){
            if(parent[i]==i){
                return i;
            }
            return findParent(parent[i],parent);

        }

        void unionsets(int x,int y,int *parent){

                int xp = findParent(x,parent);
                int yp = findParent(y,parent);
                parent[yp] = xp;


        }
        bool isCyclic(){
            int *parent = new int[V];
            for(int i=0;i<V;i++){
                parent[i] = i;
            }

            for(int i=0;i<V;i++){
                for(int j:l[i]){
                    int firstSet = findParent(i,parent);
                    int secondSet = findParent(j,parent);

                    if(firstSet==secondSet){
                        return true;
                    }
                    unionsets(i,j,parent);
                }
            }
            return false;

        }


};


int main(){


    Graph g(6);
    g.addEdge(0,1,false);
    g.addEdge(0,2,false);
    g.addEdge(0,4,false);
    g.addEdge(2,4,false);
    g.addEdge(1,4,false);
    g.addEdge(4,5,false);

    g.topologicalSort();

    Graph g2(2);
    g2.addEdge(0,1);
   // g2.addEdge(0,4);
    //g2.addEdge(1,4);
//    g2.addEdge(1,2);
//    g2.addEdge(2,3);
//    g2.addEdge(4,3);

    if(g2.isCyclic()){
        cout<<"Cyclic Graph "<<endl;
    }
    else{
        cout<<"Not Cyclic Graph"<<endl;
    }




}
