// implimentation of stack using tow queue

#include<iostream>
#include<queue>
using namespace std;
class Stack{
    queue<int> q1,q2;
    public:
    void push_value(int data){
        if(q1.empty()){
            q1.push(data);
        }else{
            while(!q1.empty()){
                q2.push(q1.front());
                q1.pop();
            }
            q1.push(data);
            while(!q2.empty()){
                q1.push(q2.front());
                q2.pop();
            }
        }
    }
    void pop_value(){
        if(q1.empty()){
            cout<<"Stack is empty"<<endl;
            return;
        }
        q1.pop();
    }

    int front_value(){
        if(q1.empty()){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        return q1.front();
    }

    bool empty(){
        return  q1.empty();
    }
};
int main(){
    Stack s;
    s.push_value(1);
    s.push_value(2);
    s.push_value(3);
    s.push_value(4);

    s.pop_value();

    while(!s.empty()){
        cout<<s.front_value()<<endl;
        s.pop_value();
    }

    return 0;
}