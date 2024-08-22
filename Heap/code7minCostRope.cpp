// find minCost to connect N ropes
#include<iostream>
#include<queue>
using namespace std;
void minCost(vector<int> v){
    priority_queue<int,vector<int>,greater<int>> pq(v.begin(),v.end());
    int cost = 0;
    while(pq.size() > 1){
        int min1=pq.top();
        pq.pop();
        int min2=pq.top();
        pq.pop();
        cost += min1 + min2;
        pq.push(min1+min2);
    }
    cout<<"min cost of N ropes :"<<cost<<endl;
}
int main(){
    vector<int> v={1,2,3,4,5};
    minCost(v);
    return 0;
}