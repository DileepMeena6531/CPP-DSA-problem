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
void inorder(Node* root,vector<int> &v){
    if(root==NULL){
        return;
    }

    inorder(root->left,v);
    v.push_back(root->data);
    inorder(root->right,v);
}

Node* merge(vector<int> res,int st,int end){
    if(st>end){
        return NULL;
    }

    int mid=st+(end-st)/2;
    Node* root=new Node(res[mid]);
    root->left=merge(res,st,mid-1);
    root->right=merge(res,mid+1,end);

    return root;
}

Node* mergeBST(Node* root1,Node* root2){
    vector<int> res;

    inorder(root1,res);
    inorder(root2,res);
    sort(res.begin(),res.end());
    
    return merge(res,0,res.size()-1);
}
int main(){
    Node* root1=new Node(2);
    root1->left=new Node(1);
    root1->right=new Node(4);

    Node* root2=new Node(9);
    root2->left=new Node(3);
    root2->right=new Node(12);

    Node* root=mergeBST(root1,root2);

    cout<<root->data;
    return 0;
}