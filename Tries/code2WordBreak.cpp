#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Node{
    public:
    unordered_map<char,Node*> children;
    bool isEndOfWord;
    Node(){
        isEndOfWord = false;
    }
};
class Tries{
    Node* root;
    public:
    Tries(){
        root=new Node();
    }

    void insert(string key){
        Node* temp=root;
        for(int i=0; i<key.size(); i++){
            if(temp->children.count(key[i])==0){
                temp->children[key[i]]=new Node();
            }
            temp=temp->children[key[i]];
        }
        temp->isEndOfWord=true;
    }

    bool search(string key){
        Node* temp=root;
        for(int i=0; i<key.size(); i++){
            if(temp->children.count(key[i])){
                temp=temp->children[key[i]];
            }else{
                return false;
            }
        }
        return temp->isEndOfWord;
    }
};
bool helper(Tries &tr,string key){
    if(key.size()==0){
        return true;
    }
    
    for(int i=0; i<key.size(); i++){
        string first=key.substr(0,i+1);
        string second=key.substr(i+1);
        if(tr.search(first) && helper(tr,second)){
            return true;
        }
    }

    return false;

}

void wordBreak(vector<string> dict,string key){
    Tries tr;
    for(int i=0; i<dict.size(); i++){
        tr.insert(dict[i]);
    }

    cout<<helper(tr,key);
}
int main(){
    vector<string> dict={"i","like","sam","samsung","mobile","phone"};

    wordBreak(dict,"ilikesam");

    return 0;
}