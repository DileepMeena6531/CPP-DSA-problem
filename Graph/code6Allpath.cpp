// find all path exist from src to dest
#include<iostream> 
#include<vector>
#include<list>
using namespace std;
class Graph{
    int V;
    list<int> *l;
    bool isCheck;
    public:
    Graph(int V,bool isCheck=true){
        this->V=V;
        l=new list<int>[V];
        this->isCheck=isCheck;
    }

    void addEdges(int u, int v){
        l[u].push_back(v);
        if(isCheck){
            l[v].push_back(u);
        }
    }
    void pathHelper(int src,int dest,string &ans,vector<bool> &vis){
        if(src==dest){
            cout<<ans<<dest<<endl;
            return;
        }
        
        vis[src]=true;
        ans+=to_string(src);
        list<int> neigh=l[src];
        for(auto v:neigh){
            if(!vis[v]){
                pathHelper(v,dest,ans,vis);
            }
        }
        ans=ans.substr(0,ans.size()-1);
        vis[src]=false;
    }
    void allPath(int src,int dest){
        string ans="";
        vector<bool> vis(V,false);
        pathHelper(src,dest,ans,vis);
    }
    
};
int main(){
    Graph g(6,false);
    g.addEdges(0,3);
    g.addEdges(2,3);
    g.addEdges(3,1);
    g.addEdges(4,0);
    g.addEdges(4,1);
    g.addEdges(5,0);
    g.addEdges(5,2);

    g.allPath(5,1);

    return 0;
}