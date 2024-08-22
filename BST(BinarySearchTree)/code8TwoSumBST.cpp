// Question 4 : Given two binary search trees, return True if and only if there is a node in
// the first tree and a node in the second tree whose values sum up to a given integer
// target.

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left=right=NULL;
    }
};
bool search(Node* root1,Node* root2, int k){
    if(root1==NULL){
        return false;
    }
    Node* temp=root1;

    while(temp!=NULL){
        if(temp->data==k){
            cout<<"pair found: "<<temp->data<<" + "<<root2->data<<endl;
            return true;
        }
        if(temp->data < k){
            temp=temp->right;
        }else{
            temp=temp->left;
        }
    }

    return false;
}

bool isPairPresent(Node* root1,Node* root2,int target){
    if(root2==NULL){
        return false;
    }

    return search(root1,root2,target-root2->data) || isPairPresent(root1,root2->left,target) || isPairPresent(root1,root2->right,target);
}

int main(){
    Node* root1=new Node(2);
    root1->left=new Node(1);
    root1->right=new Node(3);

    Node* root2=new Node(4);
    root2->left=new Node(3);
    root2->right=new Node(5);

    cout<<isPairPresent(root1,root2,5);

    return 0;
}
