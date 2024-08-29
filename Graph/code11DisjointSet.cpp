// disjoint set
#include<iostream>
#include<vector>
using namespace std;
class Disjoint{
    public:
    int n;
    vector<int> par;
    vector<int> rank;

    Disjoint(int n){
        this->n=n;
        for(int i=0; i<n; i++){
            par.push_back(i);
            rank.push_back(0);
        }
    }

    int find(int x){
        if(par[x]==x){
            return x;
        }
        return find(par[x]);
    }
    void unionRank(int a,int b){
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

    void getInfo(){
        for(int j=0; j<n; j++){
        cout<<j<<" : "<<par[j]<<","<<rank[j]<<endl;
        }
    }

};
int main(){
    Disjoint d(6);

    d.unionRank(0,2);
    cout<<d.find(2)<<endl;
    d.unionRank(1,3);
    d.unionRank(2,5);
    d.unionRank(0,3);
    cout<<d.find(2)<<endl;
    d.unionRank(0,4);

    d.getInfo();

    return 0;
}