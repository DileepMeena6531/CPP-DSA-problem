#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
void solve(vector<int> v,int target){
    unordered_map<int,int> m;

    for(int i=0; i<v.size(); i++){
        if(m.find(target-v[i])!=m.end()){
            cout<<m[target-v[i]]<<" "<<i<<endl;
        }
        m[v[i]]=i;
    }
}
int main(){
    vector<int> v={2,5,3,6,4,7,9};
    int target=9;

    solve(v,target);
    return 0;
}