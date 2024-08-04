// MIn Absolute difference pair

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){

    vector<int> A={2,4,1,6};
    vector<int> B={5,2,7,3};

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int AbsDiff=0;

    for(int i=0; i<A.size(); i++){
        AbsDiff+=abs(A[i]-B[i]);
    }

    cout<<AbsDiff<<endl;

    return 0;
}