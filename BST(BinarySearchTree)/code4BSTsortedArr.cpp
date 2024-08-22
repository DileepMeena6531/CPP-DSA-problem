// sorted array to balanced BST
#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data=val;
        left=right=NULL;
    }
};

Node* buildBSTfromSorted(int *arr,int st,int end){
    if(st>end){
        return NULL;
    }

    int mid=st+(end-st)/2;
    Node* root=new Node(arr[mid]);

    root->left=buildBSTfromSorted(arr,st,mid-1);
    root->right=buildBSTfromSorted(arr,mid+1,end);

    return root;
}
void preorder(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
int main(){
    int arr[9]={1,2,3,4,5,6,7,8,9};
    Node* root=buildBSTfromSorted(arr,0,8);
    
    preorder(root);
    return 0;
}