#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    
    Node(int val){
        data=val;
        next=NULL;
    }
};
class Queue{
    
    Node* head;
    Node* tail;
    public:

    Queue(){
        head=NULL;
        tail=NULL;
    }

    void push(int val){
        Node* newNode=new Node(val);
        if(head==NULL){
            head=newNode;
            tail=newNode;
        }
        else{
            tail->next=newNode;
            tail=newNode;
        }
    }

    void pop(){
        if(empty()){
            cout<<"List is empty"<<endl;
            return;
        }

        Node* temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }

    int front(){
        if(empty()){
            cout<<"List is empty"<<endl;
            return -1;
        }
        return head->data;
    }

    bool empty(){
        if(head==NULL){
            return true;
        }

        return false;
    }


};

int main(){

    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    
    while(!q.empty()){
        cout<<q.front()<<endl;
        q.pop();
    }

    return 0;
}