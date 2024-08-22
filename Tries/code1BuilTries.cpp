#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Node{
    public:
    unordered_map<char,Node*> children;
    bool endOfWord;
    Node(){
        endOfWord=false;
    }
};

class Tries{
    Node* root;
    public:
    Tries(){
        root=new Node();
    }

    void insert(string key){ // O(L)
        Node* temp=root;

        for(int i=0;i<key.size(); i++){
            if(temp->children.count(key[i])==0){
                temp->children[key[i]] = new Node();
            }
            temp=temp->children[key[i]];
        }
        temp->endOfWord=true;
    }

    bool search(string key){ // O(L)
        Node* temp=root;

        for(int i=0;i<key.size(); i++){

            if(temp->children.count(key[i])){
                temp=temp->children[key[i]];
            }else{
                cout<<"Word not found"<<endl;
                return false;
            }
        }
        
        if(temp->endOfWord){
            cout<<"word is present"<<endl;
            return true;
        }else{
            cout<<"word not found"<<endl;
            return false;
        }
    }
};

int main(){

    vector<string> str={"the","a","there","their","any","thee"};

    Tries tr;
    for(int i=0; i<str.size(); i++){
        tr.insert(str[i]);
    }

    tr.search("thee");


    return 0;
}