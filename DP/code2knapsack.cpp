// knapsack problem using recursion, memoization and tabulation
#include<iostream>
#include<vector>
using namespace std;

// Recursion 
int knapSackRec(vector<int> val,vector<int> wt,int W,int n){
    if(n==0 || W==0){
        return 0;
    }

    if(wt[n-1]<=W){
        //include
        int ans1=knapSackRec(val,wt,W-wt[n-1],n-1)+val[n-1];

        //exclude
        int ans2=knapSackRec(val,wt,W,n-1);
        //max 
        return max(ans1,ans2);
    }else{
        //exclude
        return knapSackRec(val,wt,W,n-1);
    }
}

//memoization 
int knapsackMemo(vector<int> val,vector<int> wt,int W,int n,vector<vector<int>> &dp){
    if(n==0 || W==0){
        return 0;
    }

    if(dp[n][W]!=-1){
        return dp[n][W];
    }

    if(wt[n-1]<=W){
        //include
        int ans1=knapsackMemo(val,wt,W-wt[n-1],n-1,dp)+val[n-1];

        //exclude
        int ans2=knapsackMemo(val,wt,W,n-1,dp);
        //max 
        dp[n][W]=max(ans1,ans2);
    }else{
        //exclude
        dp[n][W]=knapsackMemo(val,wt,W,n-1,dp);
    }
    return dp[n][W];
}

// tabulation
int knapsackTabu(vector<int> val, vector<int> wt, int W, int n){

    vector<vector<int>> dp(n+1,vector<int>(W+1,0));

    for(int i=1; i<n+1; i++){
        for(int j=1; j<W+1; j++){
            if(wt[i-1]<=j){
                dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }

    return dp[n][W];
}

// unbounded knapsack
int knapsackUnbounded(vector<int> val, vector<int> wt, int W){
    int n=val.size();
    vector<vector<int>> dp(n+1,vector<int>(W,0));

    for(int i=1; i<=n; i++){
        for(int j=1; j<=W; j++){
            if(wt[i-1]<=j){
                dp[i][j]=max(val[i-1]+dp[i][j-wt[i-1]],dp[i-1][j]);
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }

    return dp[n][W];
}
int main(){
    vector<int> val={15,14,10,45,30};
    vector<int> wt={2,5,1,3,4};
    int W=7;
    int n=5;

    vector<vector<int>> dp(n+1,vector<int>(W+1,-1));

    cout<<"knapsack Memoization : "<<knapsackMemo(val,wt,W,n,dp)<<endl;

    cout<<"knapsack tabulation : "<<knapsackTabu(val,wt,W,n)<<endl;

    cout<<"unbound knapsack tabulation : "<<knapsackUnbounded(val,wt,W)<<endl;
    return 0;
}