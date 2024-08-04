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
Node *BinaryTree(vector<int> nodes)
{
    idx++;
    if (nodes[idx] == -1)
    {
        return NULL;
    }

    Node *newNode = new Node(nodes[idx]);
    newNode->left = BinaryTree(nodes);
    newNode->right = BinaryTree(nodes);
    return newNode;
}
int kthAncester(Node *root, int n, int k)
{
    if (root == NULL){
        return -1;
    }
    if(root->data==n){
        return 0;
    }

    int left = kthAncester(root->left, n, k);
    int right = kthAncester(root->right, n, k);

    if(left==-1 &&  right==-1){
        return -1;
    }

    int ancester=left==-1 ? right:left;

    if(ancester+1 ==k){
        cout<<"kth Ancester of nodes = "<<root->data<<endl;
    }
    
    return ancester+1;
}
int main()
{
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node *root = BinaryTree(nodes);
    int n = 5;
    int k = 1;

    kthAncester(root, n, k);

    return 0;
}