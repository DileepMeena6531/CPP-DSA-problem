// Transform to sum Tree
#include <iostream>
#include <vector>
#include <queue>
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
int Transform(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int left = Transform(root->left);
    int right = Transform(root->right);

    int currData = root->data;

    root->data = left + right;
    if (root->left != NULL)
    {
        root->data += root->left->data;
    }
    if (root->right != NULL)
    {
        root->data += root->right->data;
    }

    return currData;
}

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    if(root){
        q.push(root);
        q.push(NULL);
    }

    while(!q.empty()){
        Node* curr=q.front();
        q.pop();
        if(curr==NULL){
            cout<<endl;
            if(q.empty()){
                return;
            }
            q.push(NULL);

        }else{
            cout<<curr->data <<" ";

            if(curr->left){
                q.push(curr->left);
            }
            if(curr->right){
                q.push(curr->right);
            }
        }
        
    }

}

int main()
{
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node *root = BinaryTree(nodes);

    Transform(root);

    levelOrderTraversal(root);
    return 0;
}