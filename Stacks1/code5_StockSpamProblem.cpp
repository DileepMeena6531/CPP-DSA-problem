#include<iostream>
#include<stack>
#include<vector>
using namespace std;
void StockSpamProblem(vector<int> Stock,vector<int> spam){
    stack<int> s;
    s.push(0);
    spam[0]=1;

    for(int i=1; i<Stock.size(); i++){
        int currStock=Stock[i];
        while(!s.empty() && currStock>=Stock[s.top()]){
            s.pop();
        }

        if(s.empty()){
            spam[i]=i+1;
        }else{
            spam[i]=i-s.top();
        }
        s.push(i);
    }

    for(int j=0; j<spam.size(); j++){
        cout<<spam[j]<<" ";
    }
    cout<<endl;
}
int main(){
    vector<int> Stock={100,80,60,70,60,85,100};
    vector<int> spam={0,0,0,0,0,0,0};

    StockSpamProblem(Stock,spam);
    return 0;
}