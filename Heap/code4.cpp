#include<iostream>
#include<queue>
using namespace std;

struct comparePai{
    bool operator()(pair<string, int>& a, pair<string, int>& b){
        return a.second > b.second;
    }
};
int main(){
    priority_queue<pair<string,int>,vector<pair<string,int>>,comparePai> h;

    h.push(make_pair("chotu",85));
    h.push(make_pair("dileep",78));
    h.push(make_pair("aman",92));

    while(!h.empty()){
        cout<<"name: "<<h.top().first<<", "<<h.top().second<<endl;
        h.pop();
    }

    return 0;
}