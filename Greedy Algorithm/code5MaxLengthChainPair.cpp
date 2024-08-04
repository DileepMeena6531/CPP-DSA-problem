// max Length chain of pair

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool compare(pair<int,int> p1,pair<int,int> p2){
    return p1.second<p2.second;
}

int main(){

    vector<pair<int,int>> pair(5,make_pair(0,0));
    pair[0]=make_pair(5,24);
    pair[1]=make_pair(39,69);
    pair[2]=make_pair(5,28);
    pair[3]=make_pair(27,40);
    pair[4]=make_pair(50,90);

    sort(pair.begin(),pair.end(),compare);

    int currEndPoint=pair[0].second;

    int ans=1;

    for(int i=1; i<5; i++){
        if(currEndPoint<=pair[i].first){
            ans++;
            currEndPoint=pair[i].second;
        }
    }

    cout<<ans;

    return 0;
}