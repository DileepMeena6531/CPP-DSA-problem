#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Node{
    public:
    unordered_map<char,Node*> childrern;
    bool isEndOfWord;
    int freq;

    Node(){
        isEndOfWord = false;
    }
};
class Tries{
    Node* root;
    public:
    Tries(){
        root = new Node();
        root->freq=-1;
    }

    void insert(string key){
        Node* temp=root;
        for(int i=0; i<key.size(); i++){
            if(temp->childrern.count(key[i])==0){
                temp->childrern[key[i]]=new Node();
                temp->childrern[key[i]]->freq=1;
            }else{
                temp->childrern[key[i]]->freq++;
            }
            temp=temp->childrern[key[i]];
        }
        temp->isEndOfWord=true;
    }

    string getPrifix(string key){
        Node* temp=root;
        string prefix="";

        for(int i=0; i<key.size(); i++){
            prefix+=key[i];
            if(temp->childrern[key[i]]->freq==1){ 
                break;
            }
            temp=temp->childrern[key[i]];
        }
        return prefix;
    }
};

void prefixProblem(vector<string> dict){
    Tries tr;
    for(int i=0; i<dict.size(); i++){
        tr.insert(dict[i]);
    }

    for(int i=0; i<dict.size(); i++){
        cout<<tr.getPrifix(dict[i])<<" ";
    }

}

int main(){
    vector<string> dict={"zebra","dog","dove","zebronic","sil"};
    
    prefixProblem(dict);
    return 0;
}