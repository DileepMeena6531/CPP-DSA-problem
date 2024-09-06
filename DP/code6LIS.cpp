//longest increasing subsequence
#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;
int lcs(vector<int> arr1,vector<int> arr2){
    int n=arr1.size();
    int m=arr2.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m;  j++){
            if(arr1[i-1]==arr2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}

void LIS(vector<int> arr){
    unordered_set<int> s(arr.begin(),arr.end());

    vector<int> arr2;
    for(auto e:s){
        arr2.push_back(e);
    }
    sort(arr2.begin(),arr2.end());

    cout<<lcs(arr,arr2);
}
int main(){
    vector<int> arr={50,3,10,7,40,80};
    LIS(arr);
    return 0;
}