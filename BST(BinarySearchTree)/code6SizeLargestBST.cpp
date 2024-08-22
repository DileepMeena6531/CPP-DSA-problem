// size of longest BST in BT;
#include <iostream>
#include <bits/stdc++.h>
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
class Info
{
public:
    bool isBST;
    int mini;
    int maxi;
    int sz;
    Info(bool isBST, int mini, int maxi, int sz)
    {
        this->isBST = isBST;
        this->mini = mini;
        this->maxi = maxi;
        this->sz = sz;
    }
};
static int maxSize;
static Node* largestRoot;
Info *longestBST(Node *root)
{
    if (root == NULL)
    {
        return new Info(true, INT_MAX, INT_MIN, 0);
    }

    Info *leftInfo = longestBST(root->left);
    Info *rightInfo = longestBST(root->right);

    int currMin = min(root->data, min(leftInfo->mini, rightInfo->mini));
    int currMax = max(root->data, max(leftInfo->maxi, rightInfo->maxi));
    int currSz = leftInfo->sz + rightInfo->sz + 1;

    if(leftInfo->isBST && rightInfo->isBST && root->data > leftInfo->maxi && root->data < rightInfo->mini){
        if(currSz>maxSize){
            maxSize=currSz;
            largestRoot=root;
        }
        return new Info(true,currMin,currMax,currSz);
    }

    return new Info(false,currMin,currMax,currSz);
}

int main()
{
    Node *root = new Node(50);
    root->left = new Node(30);
    root->left->left = new Node(6);
    root->left->right = new Node(20);

    root->right = new Node(60);
    root->right->left = new Node(15);
    root->right->right = new Node(70);
    root->right->right->left = new Node(65);
    root->right->right->right = new Node(80);

    longestBST(root);

    cout <<"max size of BST = "<< maxSize<<endl;
    cout<<"max size of BST root node = "<<largestRoot->data;

    return 0;
}