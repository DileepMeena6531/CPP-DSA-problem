// implimentation Stack using Deque

#include<iostream>
#include<deque>
using namespace std;

class Stack{
    deque<int> dq;
    public:

    void push(int data){
        dq.push_back(data);
    }

    void pop(){
        dq.pop_back();
    }

    int top(){
        return dq.back();
    }

    bool empty(){
        return dq.empty();
    }
};

int main(){
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }

    return 0;
}