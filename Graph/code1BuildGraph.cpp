#include<iostream>
#include<vector>
#include<list>
using namespace std;
class Graph{
    int V;
    list<pair<int,int>> *l;
    public:
    Graph(int V){
        this->V=V;
        l=new list<pair<int,int>> [V];
    }

    void addEdge(int u,int v,int w){
        l[u].push_back(make_pair(v,w));
        l[v].push_back(make_pair(u,w));
    }

    void print(){
        for(int i=0; i<V; i++){
            list<pair<int,int>> neighbors=l[i];
            cout<<i<<" : ";
            for(auto v:neighbors){
                cout<<" ( "<< v.first<<", "<<v.second<<" ) ";
            }
            cout<<endl;
        }
    }
};

int main(){
    Graph g(5);

    g.addEdge(0,1,5);
    g.addEdge(1,2,1);
    g.addEdge(1,3,2);
    g.addEdge(2,3,1);
    g.addEdge(2,4,3);

    g.print();

    return 0;
}