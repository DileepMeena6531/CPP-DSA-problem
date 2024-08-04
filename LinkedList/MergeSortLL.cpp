#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
    
};

class List{
    public:
    Node* head;
    Node* tail;

    List(){
        head = NULL;
        tail = NULL;
    }
    
    void printLL(Node* head){

        Node* temp = head;
        while(temp != NULL){
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }

    void push_front(int val){
        Node* newNode=new Node(val);
        if(tail==NULL){
            head=tail=newNode;
        }
        else{
            newNode->next=head;
            head=newNode;
        }
    }
    void push_back(int val){
        Node* newNode=new Node(val);
        if(head==NULL){
            head=tail=newNode;
        }else{
            tail->next=newNode;
            tail=newNode;
        }
    }

    Node* splitLL(Node* head){
        Node* slow=head;
        Node* fast=head;
        Node* prev=NULL;
        while(fast!=NULL && fast->next!=NULL){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }

        if(prev!=NULL){
            prev->next=NULL;
        }
        return slow;
    }

    Node* merge(Node* left,Node* right){
        List ans;
        Node* i=left;
        Node* j=right;

        while(i!=NULL && j!=NULL){
            if(i->data<=j->data){
                ans.push_back(i->data);
                i=i->next;
            }else{
                ans.push_back(j->data);
                j=j->next;
            }
        }
        while(i!=NULL){
            ans.push_back(i->data);
            i=i->next;
        }
        while (j!=NULL)
        {
            ans.push_back(j->data);
            j=j->next;
        }
        return ans.head;
    }

    Node* mergeSort(Node* head){
        //base case
        if(head==NULL || head->next==NULL){
            return head;
        }

        Node* rightSlow=splitLL(head);

        Node* left=mergeSort(head);
        Node* right=mergeSort(rightSlow);

        return merge(left,right);

    }
};

int main(){

    List ll;
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(6);
    ll.push_front(4);
    ll.push_front(5);
    ll.push_front(3);

    ll.printLL(ll.head);
    ll.head=ll.mergeSort(ll.head);

    ll.printLL(ll.head);
   

    return 0;
}