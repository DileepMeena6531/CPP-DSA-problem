//Sliding window maximum
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
void slidingWindow(vector<int> v, int k){
    priority_queue<pair<int,int>> pq;
    for(int i=0; i<k; i++){
        pq.push({v[i],i});
    }
    cout<<pq.top().first<<" ";
    for(int i=k; i<v.size(); i++){
        while(!pq.empty() && pq.top().second <=(i-k)){
            pq.pop();
        }
        pq.push({v[i],i});
        cout<<pq.top().first<<" ";
    }
}
int main(){
    vector<int> v={1,3,-2,5,2,8,6,9,7};
    int k=3;
    slidingWindow(v,k);
}