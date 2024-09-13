// we solve problem fibonacci using memoization and tabulation
#include<iostream>
#include<vector>
using namespace std;

int fiboRec(int n){
    if(n==0 || n==1){
        return n;
    }

    return fiboRec(n-1)+fiboRec(n-2);
}

//memoization
int DPfibonacci(int n,vector<int> &f){
    if(n==0 || n==1){
        return n;
    }

    if(f[n]!=-1){
        return f[n];
    }
    f[n]=DPfibonacci(n-1,f)+DPfibonacci(n-2,f);
    return f[n];
}

// tabulation
int fiboTabu(int n, vector<int> &dp){
    dp[0]=0;
    dp[1]=1;

    for(int i=2; i<=n; i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}

int main(){
    int n;
    cin>>n;

    //recurstion
    cout<<"Recursion: "<<fiboRec(n)<<endl;

    // memoization
    vector<int> f(n+1,-1);

//    for(int i=0; i<=n; i++){
//     cout<<DPfibonacci(i,f)<<" ";
//    }

    cout<<DPfibonacci(n,f);
   cout<<endl;

   vector<int> dp(n+1,0);

   cout<<"Tabulation : "<<fiboTabu(n,dp)<<endl;
   
//    for(int i=0; i<=n; i++){
//     cout<<dp[i]<<" ";
//    }
    
    return 0;
}