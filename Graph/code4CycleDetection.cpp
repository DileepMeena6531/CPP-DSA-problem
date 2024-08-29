// cycle detection in undirected/directed graph
#include<iostream> 
#include<vector>
#include<list>
using namespace std;
class Graph {
    int V;
    list<int> *l;
    bool isCheck;
    public:
    Graph(int V,bool isCheck=true){
        this->V=V;
        l=new list<int>[V];
        this->isCheck=isCheck;
    }
    void addEdge(int u,int v){
        l[u].push_back(v);
        if(isCheck){
            l[v].push_back(u);
        }
    }

    //undirected
    bool isCycleHelper(int src,int par,vector<bool>& vis){
        vis[src]=true;
        list<int> neigh=l[src];
        for(auto v:neigh){
            if(!vis[v]){
                if(isCycleHelper(v,src,vis)){
                    return true;
                }
            }else{
                if(v!=par){
                    return true;
                }
            }
        }
        return false;
    }

    bool cycleDetection(){
        vector<bool> vis(V,false);
        return isCycleHelper(0,-1,vis);
    }
    //directed

    bool directedGraphHelper(int src,vector<bool> &vis,vector<bool> &recPath){
        vis[src]=true;
        recPath[src]=true;
        list<int> neigh=l[src];
        for(auto v:neigh){
            if(!vis[v]){
                if(directedGraphHelper(v,vis,recPath)){
                    return true;
                }
            }else{
                if(recPath[v]){
                    return true;
                }
            }
        }
        recPath[src]=false;
        return false;
    }

    bool cycleDetDirectGraph(){
        vector<bool> vis(V,false);
        vector<bool> recPath(V,false);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(directedGraphHelper(i,vis,recPath)){
                    return true;
                }
            }
        }
        return false;
    }
};
int main(){
    Graph g(5,false);
    g.addEdge(0,1);
    g.addEdge(2,0);
    g.addEdge(0,3);
    g.addEdge(1,2);
    g.addEdge(3,4);
    

    // cout<<g.cycleDetection()<<endl;
    
    cout<<g.cycleDetDirectGraph()<<endl;

    return 0;
}