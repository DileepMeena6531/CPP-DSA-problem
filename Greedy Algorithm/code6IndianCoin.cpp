// find min no. of coin to make change for a value V:

#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> coin={1,2,5,10,20,50,100,500,2000};
    int V=4000;
    int  ans =0;

    for(int i=coin.size()-1; i>=0; i--){

        if(V>=coin[i]){
            ans+=V/coin[i];
            V=V%coin[i];
        }
        if(V==0){
            break;
        }
    }

    cout<<ans;

    return 0;
}