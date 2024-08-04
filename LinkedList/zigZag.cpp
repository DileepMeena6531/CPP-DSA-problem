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

class List{
    public:
    Node* head;
    Node* tail;
    
    List(){
        head=NULL;
        tail=NULL;
    }

    void push_front(int val){
        Node* newNode=new Node(val);
        if(head==NULL){
            head=tail=newNode;
        }
        else{
            newNode->next=head;
            head=newNode;
        }
    }

    void print(Node* head){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }

    Node* splitMid(Node* head){
        Node* slow=head;
        Node* fast=head;
        Node* prev=NULL;

        while(fast!=NULL and fast->next!=NULL){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }

        prev->next=NULL;
        return slow;
    }
    Node* reverse(Node* head){
        Node* prev=NULL;
        Node* temp=head;
        while(temp!=NULL){
            Node* curr=temp->next;
            temp->next=prev;
            prev=temp;
            temp=curr;
        }
        return prev;
    }

    Node* zigZag(Node* head){
        Node* temp=head;

        Node* rightHead=splitMid(temp);
        Node* rightTail=reverse(rightHead);

        Node* left=head;
        Node* right=rightTail;
        Node* tail=right;
        
        while(left!=NULL and right!=NULL){
            Node* leftNext=left->next;
            Node* rightNext=right->next;

            left->next=right;
            right->next=leftNext;

            tail=right;

            left=leftNext;
            right=rightNext;
        }

        if(right!=NULL){
            tail->next=right;
        }
        return head;       
    }
};

int main(){

    List ll;
    ll.push_front(5);
    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);

    ll.print(ll.head);

    Node* newHead=ll.zigZag(ll.head);
   
    ll.print(newHead);

    return 0;
}