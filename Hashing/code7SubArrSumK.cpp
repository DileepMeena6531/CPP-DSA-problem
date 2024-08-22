//subarray sum equal to K
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int subArrSum(vector<int> v,int k){
    unordered_map<int,int> m{make_pair(0,1)};

    int sum = 0, cnt = 0;
    for(int i=0; i<v.size(); i++){
        sum+=v[i];
        if(m.count(sum-k)){
            cnt+=m[sum-k];
        }
           m[sum]++;
    }

    return cnt;
}
int main(){
    vector<int> v={1,2,3};
    int k=3;

    cout<<subArrSum(v,k);
    return 0;
}