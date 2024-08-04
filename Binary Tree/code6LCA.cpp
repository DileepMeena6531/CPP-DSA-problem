// Lowest common Ancestor
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
bool valueOfPath(Node *root, int n, vector<int> &path)
{
    if (root == NULL)
    {
        return false;
    }

    path.push_back(root->data);
    if (root->data == n)
    {
        return true;
    }
    bool isLeft = valueOfPath(root->left, n, path);
    bool isRight = valueOfPath(root->right, n, path);

    if (isLeft || isRight)
    {
        return true;
    }

    path.pop_back();
    return false;
}
int LCA(Node *root, int n1, int n2)
{

    vector<int> path1;
    vector<int> path2;

    valueOfPath(root, n1, path1);
    valueOfPath(root, n2, path2);

    int lca = -1;
    for (int i = 0, j = 0; i < path1.size() && j < path2.size(); i++, j++)
    {
        if (path1[i] != path2[j])
        {
            return lca;
        }
        lca = path1[i];
    }
    return lca;
}

// second approach to find LCA O(N), O(1)

Node* LCA2(Node* root, int n1,int n2){
    if(root==NULL){
        return NULL;
    }

    if(root->data==n1 || root->data== n2){
        return root;
    }

    Node* leftLCA=LCA2(root->left,n1,n2);
    Node* rightLCA=LCA2(root->right,n1,n2);

    if(leftLCA!=NULL and rightLCA!=NULL){
        return root;
    }

    return leftLCA==NULL ? rightLCA : leftLCA;
    
    // if(leftLCA==NULL && rightLCA==NULL){
    //     return NULL;
    // }
    // if(leftLCA==NULL && rightLCA!=NULL){
    //     return rightLCA;
    // }
    // if(leftLCA!=NULL && rightLCA==NULL){
    //     return leftLCA;
    // }
}
int main()
{
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node *root = BinaryTree(nodes);
    int n1 = 4;
    int n2 = 5;
    cout << "LCA = " << LCA(root, n1, n2)<<endl;

    cout<<"second approach to find LCA "<<endl;

    cout<<"LCA2 = "<< LCA2(root,n1,n2)->data <<endl;

    return 0;
}