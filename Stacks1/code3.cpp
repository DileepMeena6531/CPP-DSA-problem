#include<iostream>
using namespace std;

template<class T>
class Node{
    public:
    T data;
    Node<T>* next;
    public:
    Node(T val){
        data=val;
        next=NULL;
    }
};
template<class T>
class Stack{
    Node<T>* head;
    public:
    Stack(){
        head=NULL;
    }

    void push(T val){
        Node<T>* newNode=new Node<T>(val);
        if(head==NULL){
            head=newNode;
        }else{
            newNode->next=head;
            head=newNode;
        }
    }

    void pop(){
        if(head==NULL){
            cout<<"Stack is empty"<<endl;
        }else{
            Node<T>* temp=head;
            head=head->next;
            temp->next=NULL;
            delete temp;
        }
    }

    T top(){
       if(head==NULL){
        cout<<"Stack is empty"<<endl;
       } else{
        return head->data;
       }
    }

    bool isEmpty(){
        if(head==NULL){
            return true;
        }else{
            return false;
        }
    }
};
int main(){

    Stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);


    while(!s.isEmpty()){
        cout<<s.top()<<endl;
        s.pop();
    }

    return 0;
}