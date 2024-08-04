// kth level of tree (second approach)
#include<iostream>
#include<vector>
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
static int idx=-1;
Node* BinaryTree(vector<int> nodes){
    idx++;
    if(nodes[idx]==-1){
        return NULL;
    }

    Node* newNode=new Node(nodes[idx]);
    newNode->left=BinaryTree(nodes);
    newNode->right=BinaryTree(nodes);
    return newNode;
}
void kthLevelHelper(Node* root,int k,int count){
    if(root==NULL){
        return;
    }

    if(k==count){
        cout<<root->data<<" ";
        return;
    }
    kthLevelHelper(root->left,k,count+1);
    kthLevelHelper(root->right,k,count+1);

}
void kthLevel(Node* root,int k){
    kthLevelHelper(root,k,1);
}
int main(){
    vector<int> nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root=BinaryTree(nodes);
    kthLevel(root,2);
    return 0;
}