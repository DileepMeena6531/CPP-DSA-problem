// Build tree from preorder

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

    Node *currNode = new Node(nodes[idx]);
    currNode->left = BinaryTree(nodes);
    currNode->right = BinaryTree(nodes);

    return currNode;
}
// preOrder traversal
void preOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";

    preOrder(root->left);
    preOrder(root->right);
}
// inOrder traversal
void inOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

// postOrder traversal
void postOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

// level order traversal
void levelOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();
        if (curr == NULL)
        {
            cout << endl;
            if (q.empty())
            {
                break;
            }
            q.push(NULL);
        }
        else
        {
            cout << curr->data << " ";
            if (curr->left != NULL)
            {
                q.push(curr->left);
            }
            if (curr->right != NULL)
            {
                q.push(curr->right);
            }
        }
    }
}

int height(Node* root){
    if(root==NULL){
        return 0;
    }

    int left_height=height(root->left);
    int right_height=height(root->right);

    int ans= max(left_height,right_height)+1;
    
    return ans;
}

int Count(Node* root){
    if(root==NULL){
        return 0;
    }

    int ans=Count(root->left)+Count(root->right)+1;
    return ans;
}


int totalSum(Node* root){
    if(root==NULL){
        return 0;
    }

    int left=totalSum(root->left);
    int right=totalSum(root->right);


    return left+right+root->data;

}
//Diameter of tree O(n^2)
int Diameter(Node* root){  
    if(root==NULL){
        return 0;
    }

    int currDiam=height(root->left)+height(root->right)+1;
    int leftDiam=Diameter(root->left);
    int rightDiam=Diameter(root->right);

    return max(currDiam,max(leftDiam,rightDiam));
}
//diameter of tree in TC O(n)
pair<int,int> Diam(Node* root){
    if(root==NULL){
        return make_pair(0,0);
    }

    //(diameter,height)
    pair<int,int> left=Diam(root->left);
    pair<int,int> right=Diam(root->right);

    int currDiam=left.second+right.second+1;
    int finalDiam=max(currDiam,max(left.first,right.first));
    int finalHt=max(left.second,right.second)+1;

    return make_pair(finalDiam,finalHt);

}

int main()
{
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    Node *root = BinaryTree(nodes);

    cout << "preOrder traversal = ";
    preOrder(root);
    cout << endl;

    cout << "inorder traversal = ";
    inOrder(root);

    cout << endl;

    cout << "postOrder traversal = ";
    postOrder(root);

    cout << endl;

    cout << "level Order traversal = "<<endl;
    levelOrder(root);

    cout << endl;

    cout << "Height of tree = ";
    cout << height(root);

    cout << endl;

    cout << "count of tree = ";
    cout << Count(root);

    cout << endl;

    cout << "sum of nodes in tree = ";
    cout << totalSum(root);

    cout<<endl;

    cout<<"diameter of tree = ";
    cout<<Diameter(root);

    cout<<endl;

    cout<<"diameter and heigh of tree = ";
    cout<<Diam(root).first<<" , "<< Diam(root).second;

    return 0;
}