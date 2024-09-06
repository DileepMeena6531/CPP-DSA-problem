// longest common subsequence and substring

#include<iostream>
#include<vector>
using namespace std;
//recursion
int commonSubSeq(string str1,string str2){
    int n=str1.size();
    int m=str2.size();
    
    if(n==0 || m==0){
        return 0;
    }

    if(str1[n-1]==str2[m-1]){
        return 1+commonSubSeq(str1.substr(0,n-1),str2.substr(0,m-1));
    }else{
        int ans1=commonSubSeq(str1.substr(0,n-1),str2);
        int ans2=commonSubSeq(str1,str2.substr(0,m-1));
        return max(ans1,ans2);
    }
}

// memoization

int lcsMemo(string str1,string str2,vector<vector<int>> &dp){
    int n=str1.size();
    int m=str2.size();
    
    if(n==0 || m==0){
        return 0;
    }

    if(dp[n][m]!=-1){
        return dp[n][m];
    }

    if(str1[n-1]==str2[m-1]){
        dp[n][m]=1+lcsMemo(str1.substr(0,n-1),str2.substr(0,m-1),dp);
    }else{
        int ans1=lcsMemo(str1.substr(0,n-1),str2,dp);
        int ans2=lcsMemo(str1,str2.substr(0,m-1),dp);
        dp[n][m]=max(ans1,ans2);
    }
    return dp[n][m];
}

int lcsTabul(string str1,string str2){
    int n=str1.size();
    int m=str2.size();

    vector<vector<int>> dp(n+1,vector<int> (m+1,0));

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m;  j++){
            if(str1[i-1]==str2[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}

// Longest common substring : tabulation
int longestCommSubStr(string str1,string str2){
    int n=str1.size();
    int m=str2.size();

    int ans=0;
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(str1[i-1]==str2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
                ans=max(ans,dp[i][j]);
            }else{
                dp[i][j]=0;
            }
        }
    }
    return ans;
}

int main(){ 
    string str1="abcde";
    string str2="abgce";
    cout<<"lcs recursion : "<<commonSubSeq(str1,str2)<<endl;

    vector<vector<int>> dp(str1.size()+1,vector<int>(str2.size()+1,-1));
    cout<<"lcs memoi : "<<lcsMemo(str1,str2,dp)<<endl;

    cout<<"lcs tabulation : "<<lcsTabul(str1,str2)<<endl;

    cout<<"longest common substr : "<<longestCommSubStr(str1,str2)<<endl;

    return 0;
}