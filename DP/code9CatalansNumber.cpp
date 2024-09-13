#include <iostream>
#include <vector>
using namespace std;
int catalanNumb(int n){
    if(n==0 || n==1){
        return 1;
    }

    int ans=0;
    for(int i=0; i<n; i++){
        ans+=catalanNumb(i)*catalanNumb(n-i-1);
    }
    return ans;
}
int catalanMemoi(int n,vector<int> &dp){
    if(n==0 || n==1){
        return 1;
    }

    if(dp[n]!=-1){
        return dp[n];
    }

    int ans=0;

    for(int i=0; i<n; i++){
        ans+=catalanMemoi(i,dp)*catalanMemoi(n-i-1,dp);
    }
    return dp[n]=ans;
}

// Tabulation

int catalanTabu(int n){
    vector<int> dp(n+1,0);
    dp[0]=1;
    dp[1]=1;

    for(int i=2; i<=n; i++){
        for(int j=0; j<i; j++){
            dp[i]+=dp[j]*dp[i-j-1];
        }
    }

    return dp[n];
}

int main(){
    int n=4;

    cout<<"Recursion : "<<catalanNumb(n)<<endl;

    vector<int> dp(n+1,-1);
    dp[0]=1;
    dp[1]=1;
     
    cout<<"Memoization : "<<catalanMemoi(n,dp)<<endl;

    cout<<"Tabulation : "<<catalanTabu(n)<<endl;

    return 0;
}