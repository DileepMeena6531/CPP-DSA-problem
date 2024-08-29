// minimum spaninig tree -> prism algorithm
#include<iostream>
#include<list>
#include<queue>
using namespace std;
class Graph{
    int V;
    list<pair<int,int>> *l;
    public:
    Graph(int V){
        this->V=V;
        l=new list<pair<int,int>>[V];
    }

    void addEdges(int v, int u, int wt){
        l[u].push_back(make_pair(v,wt));
        l[v].push_back(make_pair(u,wt));
    }

    void isMST(int src){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<bool> vis(V,false);
        pq.push(make_pair(0,src));
        int ans=0;

        while(pq.size()>0){
            int v=pq.top().second;
            int wt=pq.top().first;
            pq.pop();
            
            if(!vis[v]){
                ans+=wt;
                vis[v]=true;
                list<pair<int,int>> neigh=l[v];
                for(auto e:neigh){
                    pq.push(make_pair(e.second,e.first));
                }
            }
        }
        cout<<"cost of MST is : "<<ans;
    }
};

int main(){
    Graph g(4);
    g.addEdges(0,1,10);
    g.addEdges(0,3,30);;
    g.addEdges(0,2,15);
    g.addEdges(1,3,40);
    g.addEdges(2,3,55);

    g.isMST(0);

    return 0;
}