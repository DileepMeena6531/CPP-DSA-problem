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

void dijkstras(int src,vector<vector<Edge>> Graph,int V){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> dist(V,INT_MAX);
    pq.push(make_pair(0,src));
    dist[src]=0;

    while(!pq.empty()){
        int u=pq.top().second;
        pq.pop();
        vector<Edge> neigh=Graph[u];
        for(auto e:neigh){
            if(dist[e.v]>dist[u]+e.wt){
                dist[e.v]=dist[u]+e.wt;
                pq.push(make_pair(dist[e.v],e.v));
            }
        }
    }

    for(int i=0; i<V; i++){
        cout<<dist[i]<<" ";
    }
    cout<<endl;
    

}
int main(){
    vector<vector<Edge>> Graph(3);

    // Graph[0].push_back(Edge(1,2));
    // Graph[0].push_back(Edge(2,4));

    // Graph[1].push_back(Edge(2,1));
    // Graph[1].push_back(Edge(3,7));

    // Graph[2].push_back(Edge(4,3));
    // Graph[3].push_back(Edge(5,1));

    // Graph[4].push_back(Edge(3,2));
    // Graph[4].push_back(Edge(5,5));

    Graph[0].push_back(Edge(1,5));
    Graph[0].push_back(Edge(2,2));
    Graph[1].push_back(Edge(2,-10));

    dijkstras(0,Graph,3);

    return 0;
}