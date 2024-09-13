//minimum partioning
#include<iostream>
#include<vector>
using namespace std;
int minPartion(int arr[],int n){
    int sum=0;
    for(int i=0; i<n; i++){
        sum+=arr[i];
    }

    int k=sum/2;
    vector<vector<int>> dp(n+1,vector<int> (k+1,0));

    for(int i=1; i<=n; i++){
        for(int j=1; j<=k; j++){
            if(arr[i-1]<=j){
                dp[i][j]=max(arr[i-1]+dp[i-1][j-arr[i-1]],dp[i-1][j]);
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }

    int group1=dp[n][k];
    int group2=sum-group1;

    return abs(group1-group2);

}
int main(){
    int arr[]={2,3,1,4,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<minPartion(arr,n);

    return 0;
}