#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int val){
        data=val;
        next=prev=NULL;
    }
};
class DoublyLL{
    public:
    Node* head;
    Node* tail;

    DoublyLL(){
        head=tail=NULL;
    }

    void push_fornt(int val){
        Node* newNode=new Node(val);
        if(head==NULL){
            head=tail=newNode;
        }else{
            newNode->next=head;
            head->prev=newNode;
            head=newNode;
        }
    }

    void pop_front(){
        if(head==NULL){
            cout<<"List is empty"<<endl;
            return;
        }

        Node* temp=head;
        head=head->next;
        if(head!=NULL){
            head->prev=NULL;
        }
        temp->next=NULL;
        delete temp;
    }

    void print(Node* head){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp=temp->next;   
        }
        cout<<"NULL"<<endl;
    }

};
int main(){
    DoublyLL dll;

    dll.push_fornt(5);
    dll.push_fornt(4);
    dll.push_fornt(3);
    dll.push_fornt(2);
    dll.push_fornt(1);

    dll.print(dll.head);

    dll.pop_front();
    dll.pop_front();
    dll.pop_front();
    
    dll.print(dll.head);


    return 0;
}