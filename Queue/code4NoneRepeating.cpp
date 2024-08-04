//first none repeating letter in a string

#include <iostream>
#include <queue>
using namespace std;
void noneRepeatingChar(string s){
    queue<char> q;
    int freq[26]={0};

    for(int i=0; i<s.size(); i++){
        char ch=s[i];
        freq[ch-'a']++;
        q.push(ch);

        while(!q.empty() && freq[q.front()-'a']>1){
            q.pop();
        }

        if(q.empty()){
            cout<<"-1"<<" ";
        }else{
            cout<<q.front()<<" ";
        }
    }
}

int main(){
    string s="aabccxb";

    noneRepeatingChar(s);

    return 0;
}