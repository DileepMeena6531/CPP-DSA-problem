//convert BST to balanced BST
#include<iostream>
#include<vector>
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
Node* invert(Node *root,int val){
    if(root==NULL){
        root=new Node(val);
        return root;
    }

    if(val < root->data){
        root->left=invert(root->left,val);
    }else{
        root->right=invert(root->right,val);
    }
}
Node* buildBST(int *arr, int n){
    Node* root=NULL;
    for(int i=0;i<n; i++){
        root=invert(root,arr[i]);
    }
    return root;
}
void inorder(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";

    inorder(root->left);
    inorder(root->right);
}

void inOrderVal(Node* root, vector<int>& res){
    if(root==NULL){
        return;
    }
    inOrderVal(root->left,res);
    res.push_back(root->data);
    inOrderVal(root->right,res);
}

Node* balanceBST(vector<int> &res,int st,int end){
    if(st>end){
        return NULL;
    }

    int mid=st+(end-st)/2;
    Node* root=new Node(res[mid]);
    root->left=balanceBST(res,st,mid-1);
    root->right=balanceBST(res,mid+1,end);
    return root;
}
Node* bstToBalanceBST(Node* root){
    vector<int> res;
    inOrderVal(root,res);

    root=balanceBST(res,0,res.size()-1);
    return root;
}

int main(){
    int arr[7]={6,5,4,3,7,8,9};
    Node* root=buildBST(arr,7);
    inorder(root);
    cout<<endl;

    root=bstToBalanceBST(root);
    inorder(root);
    return 0;
}