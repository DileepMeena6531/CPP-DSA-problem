#include<iostream>
#include<vector>
#include<list>
using namespace std;
template<class T>
class Stack{
    list<T> l;
    public:

    void push(T val){
        l.push_front(val);
    }

    void pop(){
        l.pop_front();
    }

    T top(){
        return l.front();
    }

    bool isEmpty(){
        return l.size()==0;
    }

};
int main(){
   Stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    while(!s.isEmpty()){
        cout<<s.top()<<endl;
        s.pop();
    }

    return 0;
}