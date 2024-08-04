// cheack subtree of another tree is identical
#include <iostream>
#include <vector>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
static int idx = -1;
Node* BinaryTree(vector<int> nodes)
{
    idx++;
    if(nodes[idx]==-1){
        return NULL;
    }

    Node *newNode = new Node(nodes[idx]);
    newNode->left = BinaryTree(nodes);
    newNode->right=BinaryTree(nodes);

    return newNode;
}
bool isIdentical(Node* root1,Node* root2){
    if(root1==NULL && root2==NULL){
        return true;
    }
    if(root1==NULL || root2==NULL){
        return false;
    }

    if(root1->data!=root2->data){
        return false;
    }

    return isIdentical(root1->left,root2->left) && isIdentical(root1->right,root2->right);


}
bool isSubtree(Node* root,Node* subTree){
    if(root==NULL && subTree==NULL){
        return true;
    }
    if(root==NULL || subTree==NULL){
        return false;
    }

    if(root->data==subTree->data){
        if(isIdentical(root,subTree)){
            return true;
        }
    }

    int isLeftTree=isSubtree(root->left,subTree);
    if(!isLeftTree){
        return isSubtree(root->right,subTree);
    }

    return true;

}

int main()
{
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node *root = BinaryTree(nodes);
    
    Node* subTree=new Node(2);
    subTree->left=new Node(4);
    subTree->right=new Node(5);

    cout<<isSubtree(root,subTree);

    return 0;
}