// Graph Traversal as BFS / DFS
#include<iostream>
#include<vector>
#include<queue>
#include<list>
using namespace std;
class Graph{
    int V;
    list<int> *l;
    public:
    Graph(int V){
        this->V = V;
        l = new list<int>[V];
    }

    void addEdges(int u,int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void print(){
        for(int i=0; i<V; i++){
            list<int> neigh=l[i];
            cout<<i<<" : ";
            for(auto v:neigh){
                cout<<v<<" ";
            }
            cout<<endl;
        }
    }

// traversal as BFS
    void BFShelper(int st,vector<bool> &vis){ // O(V + E)
        queue<int> q;
        q.push(st);
        vis[st]=true;

        while(q.size()>0){
            int u=q.front();
            list<int> neigh=l[u];
            q.pop();
            for(auto v: neigh){
                if(!vis[v]){
                    vis[v]=true;
                    q.push(v);
                }
            }
            cout<<u<<" ";
        }
        cout<<endl;
    }

    void BFS(){
        vector<bool> vis(V,false);
        for(int i=0; i<V; i++){
            if(!vis[i]){
                BFShelper(i,vis);
                cout<<endl;
            }
        }
    }

//DFS traversal
    void DFShelper(int V, vector<bool> &vis){
        vis[V]=true;
        cout<<V<<" ";
        list<int> neigh=l[V];
        for(auto v:neigh){
            if(!vis[v]){
                DFShelper(v,vis);
            }
        }
    }

    void DFS(){
        vector<bool> vis(V,false);
        for(int i=0; i<V; i++){
            if(!vis[i]){
                DFShelper(i,vis);
                cout<<endl;
            }
        }
    }
};
int main(){
    Graph g(10);

    g.addEdges(0,2);
    g.addEdges(2,5);
    g.addEdges(1,6);
    g.addEdges(6,4);
    g.addEdges(4,3);
    g.addEdges(4,9);
    g.addEdges(3,7);
    g.addEdges(3,8);

    // g.print();

    g.BFS();

    g.DFS();

    return 0;
}