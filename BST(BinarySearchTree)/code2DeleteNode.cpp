// delete a node in bst
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
Node* insert(Node* root,int val){
    if(root==NULL){
        root=new Node(val);
        return root;
    }

    if(val<root->data){
        root->left=insert(root->left,val);
    }else{
        root->right=insert(root->right,val);
    }
}
Node* buildBST(int *arr,int n){
    Node* root=NULL;
    for(int i=0; i<n; i++){
        root=insert(root,arr[i]);
    }

    return root;
}

void inOrder(Node* root){
    if(root==NULL){
        return ;
    }

    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

Node* inOrderSuccessor(Node* root){
    while(root->left!=NULL){
        root=root->left;
    }
    return root;
}

Node* nodeDelete(Node* root,int val){
    if(root==NULL){
        return NULL;
    }

    if(val<root->data){
        root->left=nodeDelete(root->left,val);
    }else if(val>root->data){
        root->right=nodeDelete(root->right,val);
    }else{

        //root->data == val;
        
        //leafNode(no child)
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }

        //one child
        if(root->left==NULL || root->right==NULL){
            return root->left==NULL ? root->right:root->left;
        }

        Node* IS=inOrderSuccessor(root->right);
        root->data=IS->data;
        root->right=nodeDelete(root->right,IS->data);
        return root;
    }
    return root;
}
int main(){
    int arr[9]={8,5,3,1,4,6,10,11,14};
    Node* root=buildBST(arr,9);
    inOrder(root);
    cout<<endl;

    nodeDelete(root,5);
    inOrder(root);
    return 0;
}
