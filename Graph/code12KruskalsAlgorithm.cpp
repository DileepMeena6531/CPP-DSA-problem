//Kruskal's algorithm -> used to find minimum spanning tree 
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Edge{
    public:
    int u;
    int v;
    int wt;
    Edge(int u,int v,int wt){
        this->u=u;
        this->v=v;
        this->wt=wt;
    }
};

class Graph{
public:
    int V;
    vector<Edge> edges;
    vector<int> par;
    vector<int> rank;
    
    Graph(int V){
        this->V=V;

        for(int i=0; i<V; i++){
            par.push_back(i);
            rank.push_back(0);
        }
    } 

    int find(int x){
        if(par[x]==x){
            return x;
        }
        return par[x]=find(par[x]);
    }

    void unionByRank(int a, int b){
        int parA=find(a);
        int parB=find(b);

        if(rank[parA]==rank[parB]){
            par[parB]=parA;
            rank[parA]++;
        }else if(rank[parA]>rank[parB]){
            par[parB]=parA;
        }else{
            par[parA]=parB;
        }

    }

    void addEdges(int u,int v,int wt){
        edges.push_back(Edge(u,v,wt));
    }

    void kruskals(){
        sort(edges.begin(),edges.end(),[](Edge &a, Edge&b){return a.wt < b.wt;});
        int mstCost=0;

        for(int i=0; i<edges.size(); i++){
            Edge e=edges[i];

            int parU=find(e.u);
            int parV=find(e.v);
            if(parU!=parV){
                unionByRank(parU,parV);
                mstCost+=e.wt;
            }
        }

        cout<<"min cost of MST : "<<mstCost<<endl;
    }

};
int main(){
    Graph g(4);
    g.addEdges(0,1,10);
    g.addEdges(0,2,15);
    g.addEdges(0,3,30);
    g.addEdges(1,3,40);
    g.addEdges(2,3,50);

    g.kruskals();

    return 0;
}