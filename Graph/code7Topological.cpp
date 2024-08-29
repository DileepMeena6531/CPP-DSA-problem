//topological sorted
#include<iostream>
#include<vector>
#include<stack>
#include<list>
#include<queue>
using namespace std;
class Graph{
    int V;
    list<int>* l;
    public:
    Graph(int V){
        this->V = V;
        l = new list<int>[V];
    }

    void addEdges(int u,int v){
        l[u].push_back(v);
    }

    // topological sorting using DFS
    void dfsHelper(int src,vector<bool> &vis,stack<int> &s){
        vis[src] = true;
        list<int> neigh=l[src];
        for(auto v:neigh){
            if(!vis[v]){
                dfsHelper(v,vis,s);
            }
        }
        s.push(src);
    }

    void topoSort(){
        vector<bool> vis(V,false);
        stack<int> s;
        for(int i=0; i<V; i++){
            if(!vis[i]){
                dfsHelper(i,vis,s);
            }
        }

        while(!s.empty()){
            cout<<s.top()<<" ";
            s.pop();
        }
        cout<<endl;
    }

    //Topological sorting using BFS 
    void calIndDegree(vector<int> &indeg){
        for(int i=0; i<V; i++){
            list<int> neigh=l[i];
            for(auto v:neigh){
                indeg[v]++;
            }
        }
    }
    void bfsTopoSort(){
        vector<int> indeg(V,0);
        calIndDegree(indeg);
        queue<int> q;

        for(int i=0; i<V; i++){
                if(indeg[i]==0){
                    q.push(i);
                }
        }

        while(q.size()>0){
            int curr=q.front();
            q.pop();
            cout<<curr<<" ";
            list<int> neigh=l[curr];

            for(auto v:neigh){
                indeg[v]--;
                if(indeg[v]==0){
                    q.push(v);
                }
            }
        }
    }
};
int main(){
    Graph g(6);
    g.addEdges(2,3);
    g.addEdges(3,1);

    g.addEdges(4,0);
    g.addEdges(4,1);
    g.addEdges(5,0);
    g.addEdges(5,2);

    g.topoSort();

    g.bfsTopoSort();

    return 0;
}