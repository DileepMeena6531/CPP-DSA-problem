#include <iostream>
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
Node *insertion(Node *root, int val)
{
    if (root == NULL)
    {
        root = new Node(val);
        return root;
    }

    if (val < root->data)
    {
        root->left = insertion(root->left, val);
    }
    else
    {
        root->right = insertion(root->right, val);
    }

    return root;
}
Node *BST(int *arr, int n)
{
    Node *root = NULL;

    for (int i = 0; i < n; i++)
    {
        root=insertion(root, arr[i]);
    }

    return root;
}
void inOrderTraversal(Node* root){
    if(root==NULL){
        return;
    }

    inOrderTraversal(root->left);
    cout<<root->data<<" ";
    inOrderTraversal(root->right);

}

// search key in BST 
bool searchKey(Node* root,int key){

    if(root==NULL){
        return false;
    }

    if(root->data==key){
        return true;
    }

    if(key<root->data){
        return searchKey(root->left,key);
    }else{
        return searchKey(root->right,key);
    }

}

// print in range 

void printInRange(Node* root, int start, int end){
    if(root==NULL){
        return; 
    }

    if(start<=root->data &&  root->data<=end){
        printInRange(root->left,start,end);
        cout<<root->data<<" ";
        printInRange(root->right,start,end);
    }else if(root->data < start){
        printInRange(root->right,start,end);
    }else{
        printInRange(root->left,start,end);
    }
}
int main()
{
    int arr[9] = {8,5,3,1,4,6,10,11,14};
    Node *root = BST(arr, 9);
    cout<<"Binary search Tree inorder"<<endl;
    inOrderTraversal(root);
    cout<<endl;

    int key=10;
    
    if(searchKey(root,key)){
        cout<<"key is present in BST";
    }else{
        cout<<"key is not present in BST";
    }
    cout<<endl;

    printInRange(root,5,12);

    return 0;
}