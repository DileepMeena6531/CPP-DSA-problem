// Top view of a Binary tree
#include <iostream>
#include <vector>
#include<queue>
#include<map>
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
void topView(Node* root){
    queue<pair<Node*,int>> q;
    map<int,int> m;

    if(root){
        q.push(make_pair(root,0));
    }

    while(!q.empty()){
        pair<Node*,int> curr=q.front();
        q.pop();

        Node* currNode=curr.first;
        int currHt=curr.second;

        if(m.count(currHt)==0){
            m[currHt]=currNode->data;
        }
        if(currNode->left){
            q.push(make_pair(currNode->left,currHt-1));
        }
        if(currNode->right){
            q.push(make_pair(currNode->right,currHt+1));
        }
    }
    for(auto it:m){
        cout<<it.second<<" ";
    }
}

int main()
{
    vector<int> nodes = {1, 2, -1, 4, -1, 5, -1, 6, -1, -1, 3, -1, -1};
    Node* root=BinaryTree(nodes);
    
    topView(root);

    return 0;
}