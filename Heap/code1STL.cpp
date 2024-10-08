#include<iostream>
#include<queue>
using namespace std;

int main(){
    // priority_queue<int> pq; // in top max value
    priority_queue<int, vector<int>, greater<int>> pq;  //in top min value 
    pq.push(5);
    pq.push(10);
    pq.push(3);
    pq.push(7);

    while(!pq.empty()){
        cout<<"top : "<<pq.top()<<endl;
        pq.pop();
    }

    return 0;
}