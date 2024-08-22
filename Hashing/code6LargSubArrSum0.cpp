//find largest subarray who sum  is zero
#include<iostream>
#include<unordered_map>
#include<bits/stdc++.h>
using namespace std;
int largestArrSumZero(vector<int> v){
    int sum=0;
    int ans=0;
    unordered_map<int,int> m;

    for(int i=0; i<v.size(); i++){
        sum+=v[i];
        if(sum==0){
            ans=max(ans,i+1);
        }
        if(m.count(sum)){
            ans=max(ans,i-m[sum]);
        }else{
            m[sum]=i;
        }
    }
    return ans;
}
int main(){
    vector<int> v={15,2,-2,-8,1,7,10};

    cout<<largestArrSumZero(v);
    return 0;
}