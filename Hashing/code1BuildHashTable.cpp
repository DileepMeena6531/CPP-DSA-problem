#include<iostream>
using namespace std;
class Node{
    public:
    string key;
    int val;
    Node* next;
    Node(string key,int val){
        this->key=key;
        this->val=val;
        next=NULL;
    }
    ~Node(){
        if(next!=NULL){
            delete next;
        }
    }
};
class HashTable{
    int totSize;
    int currSize;
    Node** table;

    int hashFunction(string key){
        int idx=0;
        for(int i=0; i<key.size(); i++){
            idx=idx+(key[i]*key[i])%totSize;
        }
        return idx%totSize;
    }

    void rehash(){
        Node** oldTable=table;
        int oldSize=totSize;

        totSize=2*totSize;
        currSize=0;
        table=new Node*[totSize];

        for(int i=0; i<totSize; i++){
            table[i]=NULL;
        }

        for(int i=0; i<oldSize; i++){
            Node* temp=oldTable[i];
            while(temp!=NULL){
                insert(temp->key,temp->val);
                temp=temp->next;
            }
            if(oldTable[i]!=NULL){
                delete oldTable[i];
            }
        }
        delete []oldTable;
    }

    public:
    HashTable(int size=1){
        this->totSize=size;
        currSize=0;

        table=new Node*[totSize];
        for(int i=0; i<totSize; i++){
            table[i]=NULL;
        }
    }

    void insert(string key, int val){
        int idx=hashFunction(key);

        Node* newNode=new Node(key,val);

        newNode->next=table[idx];
        table[idx]=newNode;

        currSize++;

        double lemda=currSize/double(totSize);
        if(lemda >1){
            rehash();
        }
    }

    bool exists(string key){
        int idx=hashFunction(key);
        Node* temp=table[idx];
        while(temp!=NULL){
            if(temp->key==key){
                return true;
            }
            temp=temp->next;
        }
        return false;
    }

    
    int search(string key){
        int idx=hashFunction(key);
        Node* temp=table[idx];
        while(temp!=NULL){
            if(temp->key==key){
                return temp->val;
            }
            temp=temp->next;
        }
        return -1;
    }

    void remove(string key){
        int idx=hashFunction(key);
        Node* temp=table[idx];
        Node* prev=temp;
        while(temp!=NULL){
            if(temp->key==key){
                if(prev==temp){
                    table[idx]=temp->next;
                }else{
                    prev->next=temp->next;
                }
                break;
            }
            prev=temp;
            temp=temp->next;
        }
    }

    void print(){
        for(int i=0;i<totSize;i++){
            cout<<"idx"<<i<<"->";
            Node* temp=table[i];
            while(temp!=NULL){
                cout<<"("<<temp->key<<", "<<temp->val<<") ->";
                temp=temp->next;
            }
            cout<<"NULL"<<endl;
        }
    }

};

int main(){
    HashTable ht;
    ht.insert("India",140);
    ht.insert("usa",100);
    ht.insert("china",120);
    ht.insert("ladak",110);
    ht.insert("Noida",70);
    ht.insert("america",86);
    ht.insert("canada",99);

    // if(ht.exists("india")){
    //     cout<<" population "<<ht.search("kota")<<endl;
    // }
    ht.print();

    cout<<"------------------------------------------------"<<endl;
    ht.remove("china");
    ht.print();
    return 0;
}