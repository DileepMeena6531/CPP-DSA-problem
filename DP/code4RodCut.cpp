// Rod Cutting : maxProfit cut rod into L pieces
#include<iostream>
#include<vector>
using namespace std;
int rodeLenght(vector<int> prices,vector<int> lenght,int rodLeng){
    int n=prices.size();
    vector<vector<int>> dp(n+1,vector<int> (rodLeng+1,0));

    for(int i=1; i<=n; i++){
        for(int j=1; j<=rodLeng; j++){
            if(lenght[i-1]<=j){
                dp[i][j]=max(prices[i-1]+dp[i][j-lenght[i-1]],dp[i-1][j]);
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][rodLeng];
}
int main(){
    vector<int> prices={1,5,8,9,10,17,17,20};
    vector<int> length={1,2,3,4,5,6,7,8};
    int rodLeng=8;

    cout<<rodeLenght(prices,length,rodLeng);
    return 0;
}