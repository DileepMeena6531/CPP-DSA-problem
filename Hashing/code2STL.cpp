#include<iostream>
#include<unordered_map>
#include<unordered_set>
using namespace std;

 int main(){
    unordered_map<string,int> m;
    m["India"]=140;
    m["China"]=1400;
    m["USA"]=14000;
    m["UK"]=140000;
    m["canada"]=140;

    for(auto it:m){
        cout<<"country : "<<it.first<<", "<<it.second<<endl;
    }

    m.erase("UK");
    cout<<"----------------------------";

    for(pair<string,int> cnt:m){
        cout<<"country : "<<cnt.first<<", "<<cnt.second<<endl;
    }

    cout<<m.count("Noida")<<endl;

    cout<<"---------------------------------------------"<<endl;

    // set 
    unordered_set<int> s;
    s.insert(4);
    s.insert(8);
    s.insert(2);
    s.insert(1);
    s.insert(5);

    for(auto it: s){
        cout<<it<<" ";    
    }

    cout<<endl<<"size of set : "<<s.size()<<endl;

    s.erase(8);

    for(auto it: s){
        cout<<it<<" ";    
    }
    cout<<endl;

    if(s.find(8)!=s.end()){
        cout<<"value exist";
    }else
    {
        cout<<"not exist";
    }
    
    
    return 0;
 }