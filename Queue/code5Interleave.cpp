// Interleave two halves of a queue of even size

#include<iostream>
#include<queue>
using namespace std;
void interLeave(queue<int> &q){
    int n = q.size();
    queue<int> q2;

    for(int i=0; i<n/2; i++){
        q2.push(q.front());
        q.pop();
    }

    while(!q2.empty()){
        q.push(q2.front());
        q2.pop();
        q.push(q.front());
        q.pop();
    }
}
int main(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);

    interLeave(q);

    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }

    return 0;
}