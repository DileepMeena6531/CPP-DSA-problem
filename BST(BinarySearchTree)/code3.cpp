// root to leaf path

#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
    int data;
    Node* left; 
    Node* right;
    Node(int val){
        data =val;
        left=right=NULL;
    }
};
Node* inverse(Node* root,int val){
    if(root==NULL){
        root=new Node(val);
        return root;
    }

    if(val<root->data){
        root->left=inverse(root->left,val);
    }else{
        root->right=inverse(root->right,val);
    }
    return root;
}

Node* buildBST(int *arr,int n){
    Node* root=NULL;

    for(int i=0; i<n; i++){
        root=inverse(root,arr[i]);
    }
    return root;
}

//check validate BST


void rootToLeaf(Node* root,vector<int> &res, vector<vector<int>> &ans){
    if(root==NULL){
        return;
    }

    res.push_back(root->data);
    rootToLeaf(root->left,res,ans);
    rootToLeaf(root->right,res,ans);

    if(root->left==NULL and root->right==NULL){
        ans.push_back(res);
    }

    res.pop_back();
    return;

}
// is validata BST
bool isValidateBST(Node* root,Node* min,Node* max){
    if(root==NULL){
        return true;
    }

    if(min!=NULL && min->data > root->data){
        return false;
    }
    if(max!=NULL && max->data < root->data){
        return false;
    }

    return isValidateBST(root->left,min,root) && isValidateBST(root->right,root,max);
}

int main(){
    int arr[9]={8,5,3,1,4,6,10,11,14};
    Node* root=buildBST(arr,9);
    
    vector<vector<int>> ans;
    vector<int> res;
    rootToLeaf(root,res,ans);

    for(int i=0; i<ans.size();i++){
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"is validate BST = "<<isValidateBST(root,NULL,NULL);

    return 0;
}