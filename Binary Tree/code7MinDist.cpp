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
static int idx=-1;
Node* BinaryTree(vector<int> nodes){
    idx++;
    if(nodes[idx]==-1){
        return NULL;
    }

    Node* currNode=new Node(nodes[idx]);
    currNode->left=BinaryTree(nodes);
    currNode->right=BinaryTree(nodes);

    return currNode;
}
Node* LCA(Node* root, int n1,int n2){
    if(root==NULL){
        return NULL;
    }

    if(root->data == n1 || root->data == n2){
        return root;
    }

    Node* leftLCA=LCA(root->left,n1,n2);
    Node* rightLCA=LCA(root->right,n1,n2);

    if(leftLCA!=NULL && rightLCA!=NULL){
        return root;
    }

    return leftLCA==NULL ? rightLCA:leftLCA;
}

int Dist(Node* root,int n){
    if(root==NULL){
        return -1;
    }

    if(root->data==n){
        return 0;
    }

    int leftDis=Dist(root->left,n);
    if(leftDis!=-1){
        return leftDis+1;
    }

    int rightDis=Dist(root->right,n);
    if(rightDis!=-1){
        return rightDis+1;
    }

    return -1;
}

int MinDis(Node* root, int n1,int n2){
    Node* lca=LCA(root,n1,n2);

    int dis1=Dist(lca,n1);
    int dis2=Dist(lca,n2);

    return dis1+dis2;
}

int main(){
    vector<int> nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root=BinaryTree(nodes);
    int n1=2;
    int n2=6;

    cout<<"Min Distance b/w two nodes = "<<MinDis(root,n1,n2)<<endl;

    return 0;
}