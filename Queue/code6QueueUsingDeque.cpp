// implimentation Queue using Deque

#include<iostream>
#include<deque>
using namespace std;
class Queue{
    deque<int> dq;
    public:

    void push(int data){
        dq.push_back(data);
    }

    void pop(){
        dq.pop_front();
    }

    int front(){
        return dq.front();
    }

    bool empty(){
        return dq.empty();
    }
};

int main(){
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    while(!q.empty()){
        cout<<q.front()<<endl;
        q.pop();
    }
    return 0;
}