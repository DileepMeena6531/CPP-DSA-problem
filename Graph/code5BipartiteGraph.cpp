// check graph is bipartite or not
#include<iostream>
#include<queue>
#include<list>
#include<vector>
using namespace std;
class Graph{
    int V;
    list<int> *l;
    public:
    Graph(int V){
        this->V=V;
        l=new list<int>[V];
    }

    void addEdges(int u,int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    bool isBipartite(){
        queue<int> q;
        vector<int> color(V,-1);
        q.push(0);
        color[0]=0;
        while(q.size()>0){
            int src=q.front();
            q.pop();
            list<int> neigh=l[src];
            for(auto v: neigh){
                if(color[v]==-1){
                    color[v]=!color[src];
                    q.push(v);
                }else{
                    if(color[v]==color[src]){
                        return false;
                    }
                }
            }
        }
        return true;

    }
};
int main(){
    Graph g(4);
    g.addEdges(0,1);
    g.addEdges(1,2);
    g.addEdges(2,3);
    g.addEdges(3,0);
    g.addEdges(0,2);

    cout<<g.isBipartite();
    return 0;
}