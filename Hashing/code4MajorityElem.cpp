#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

void frequncy(vector<int> v,int n){
    unordered_map<int,int> m;

    for(int i=0; i<n; i++){
        m[v[i]]++;
    }

    for(auto it:m){
        if(it.first>=n/3){
            cout<<it.second<<" ";
        }
    }
}
//check anagram or not

bool anagram(string s1,string s2){

    if(s1.size()!=s2.size()){
        return false;
    }

    unordered_map<char,int> m1;
    
    for(int i=0;i<s1.size(); i++){
        m1[s1[i]]++;
    }

    for(int i=0; i<s2.size(); i++){
        if(m1.find(s2[i])!=m1.end()){
            m1[s2[i]]--;
        }
    }
    
    for(auto it:m1){
        if(it.second>0){
            return false;
        }
    }

    return true;
 
}
int main(){
    vector<int> v={2,3,1,5,3,1,2,2,1};
    int n=v.size();

    frequncy(v,n);

    string s1="ssq";
    string s2="qqs";

    cout<<endl<<"anagram: ";
    cout<<anagram(s1,s2);
    return 0;
}