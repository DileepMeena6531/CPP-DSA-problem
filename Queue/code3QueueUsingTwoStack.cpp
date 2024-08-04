// implimentation queue using two stack

#include<iostream>
#include<stack>
using namespace std;
class Queue{
    stack<int> s1,s2;
    public:

    void push_value(int data){
        if(s1.empty()){
            s1.push(data);
        }else{
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            s1.push(data);
            while(!s2.empty()){
                s1.push(s2.top());
                s2.pop();
            }
        }
    }

    void pop_value(){
        if(s1.empty()){
            cout<<"Queue is empty"<<endl;
            return;
        }
        s1.pop();
    }

    int front_value(){
        if(s1.empty()){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        return s1.top();
    }
};
int main(){

    Queue q;
    q.push_value(1);
    q.push_value(2);
    q.push_value(3);

    cout<<q.front_value()<<endl;

    q.pop_value();

    cout<<q.front_value()<<endl;

    return 0;
}