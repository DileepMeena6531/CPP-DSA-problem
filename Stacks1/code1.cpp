#include<iostream>
#include<vector>
using namespace std;

template<class T>

class Stack{
    vector<T> v;
    public:

    void push(T val){
        v.push_back(val);
    }

    void pop(){
        if(isEmpty()){
            cout<<"Stack is empty"<<endl;
            return;
        }
        v.pop_back();
    }

    T top(){
        int index=v.size()-1;
        return v[index];
    }
    
    bool isEmpty(){
        return v.size()==0;
    }
};
int main(){
    Stack<string> s;
    s.push("hai");
    s.push("man");
    s.push("good");
    s.push("dileep");

    while(!s.isEmpty()){
        cout<<s.top()<<endl;
        s.pop();
    }

    return 0;
}