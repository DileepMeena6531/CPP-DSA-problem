// hash path problem: if path exist from src to dest retrun true else false
#include<iostream>
#include<vector>
#include<list>
using namespace std;

class Graph{
    int V;
    list<int>* l;
    public:
    Graph(int V){
        this->V=V;
        l=new list<int>[V];
    }

    void addEdges(int u,int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }
    
    bool pathHelper(int src,int dest,vector<bool> &vis){
        if(src==dest){
            return true;
        }

        vis[src]=true;
        list<int> neigh=l[src];
        for(auto v:neigh){
            if(!vis[v]){
                if(pathHelper(v,dest,vis)){
                    return true;
                }
            }
        }
        return false;
    }

    bool hashPath(int src,int dest){
        vector<bool>  vis(V,false);
        return pathHelper(src,dest,vis);
    }

};

int main(){

     Graph g(7);

    g.addEdges(0,1);
    g.addEdges(0,2);
    g.addEdges(1,3);
    g.addEdges(2,4);
    g.addEdges(3,4);
    g.addEdges(3,5);
    g.addEdges(4,5);
    g.addEdges(5,6);

    cout<<g.hashPath(0,5);

    return 0;
}