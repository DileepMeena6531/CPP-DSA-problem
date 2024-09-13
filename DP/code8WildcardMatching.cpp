#include<iostream>
#include<vector>
using namespace std;
bool wildcardMatching(string text,string pattern){
    int n=text.size();
    int m=pattern.size();
    vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));
    dp[0][0]=true;

    for(int j=1; j<=m; j++){
        if(pattern[j-1]=='*'){
            dp[0][j]=dp[0][j-1];
        }else{
            dp[0][j]=false;
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(text[i-1]==pattern[j-1] || pattern[j-1]=='?'){
                dp[i][j]=dp[i-1][j-1];
            }
            else if(pattern[j-1]=='*'){
                dp[i][j]=dp[i-1][j] || dp[i][j-1];
            }
            else{
                dp[i][j]=false;
            }
        }
    }
    return dp[n][m];
}
int main(){
    string text="babaabab";
    string pattern="b**ba**ab*";

    cout<<wildcardMatching(text,pattern);

    return 0;
}