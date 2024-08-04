// fractional knapsack

#include<iostream> 
#include<algorithm>
#include<vector>
using namespace std;

bool compare(pair<double,int> p1, pair<double,int> p2){
    return p1.first>p2.first;
}

int FractionalKnapsack(vector<int> val,vector<int> wt, int W){
    int n = val.size();

    vector<pair<double,int>> ratio(n,make_pair(0.0,0));

    for(int i=0; i<n; i++){
        double r=val[i]/(double)wt[i];
        ratio[i]=make_pair(r,i);
    }

    sort(ratio.begin(),ratio.end(),compare);

    int ans=0;

    for(int i=0; i<n; i++){

        if(wt[ratio[i].second]<=W){
            ans+=val[ratio[i].second];
            W-=wt[ratio[i].second];
        }else{
            ans+=ratio[i].first * W;
            W=0;
            break;
        }
    }

    return ans;

}

int main(){
    vector<int> val={120,100,60};
    vector<int> wt={30,20,10};
    int W=55;

    cout<<FractionalKnapsack(val,wt, W);

    return 0;
}