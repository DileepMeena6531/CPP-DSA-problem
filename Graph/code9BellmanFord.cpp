#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;
class Edge{
    public:
    int v;
    int wt;
    Edge(int v,int wt){
        this->v=v;
        this->wt=wt;
    }
};

void bellmanFord(int src,vector<vector<Edge>> Graph,int V){
    vector<int> dist(V,INT_MAX);
    dist[src]=0;

    for(int i=0; i<V-1; i++){
        for(int j=0; j<V; j++){
            for(auto e:Graph[j]){
                if(dist[e.v]>dist[j]+e.wt){
                    dist[e.v]=dist[j]+e.wt;
                }
            }
        }
    }
    
    for(int i=0; i<V; i++){
        cout<<dist[i]<<" ";
    }
    cout<<endl;
    

}
int main(){
    vector<vector<Edge>> Graph(5);

    Graph[0].push_back(Edge(1,2));
    Graph[0].push_back(Edge(2,4));

    Graph[1].push_back(Edge(2,-4));

    Graph[2].push_back(Edge(3,2));
    Graph[3].push_back(Edge(4,4));

    Graph[4].push_back(Edge(1,-1));

    // Graph[0].push_back(Edge(1,5));
    // Graph[0].push_back(Edge(2,2));
    // Graph[1].push_back(Edge(2,-10));

    bellmanFord(0,Graph,5);

    return 0;
}
