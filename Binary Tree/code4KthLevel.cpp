// Kth level of traversal

#include <iostream>
#include <queue>
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

void kthValue(Node *root, int k)
{
    int count = 1;
    queue<Node *> q;
    if (root)
    {
        q.push(root);
        q.push(NULL);
    }

    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();

        if (curr == NULL)
        {
            count++;
            if (q.empty())
            {
                break;
            }
            q.push(NULL);
        }
        else
        {   
            
            if(count==k){
                cout << curr->data<<" ";
            }
            
            if (curr->left)
            {
                q.push(curr->left);
            }
            if (curr->right)
            {
                q.push(curr->right);
            }
        }
    }
}

int main()
{
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node *root = BinaryTree(nodes);

    int k = 3;
    kthValue(root, k);

    return 0;
}