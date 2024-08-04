#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//O(n)
void NextGreaterNumber(vector<int> arr, vector<int> ans){
        int n=arr.size();
        stack<int> s;
        s.push(n-1);
        ans[n-1]=-1;

        for(int i=n-2; i>=0; i--){

            while(!s.empty() && arr[i]>=arr[s.top()]){
                s.pop();
            }

            if(s.empty()){
                ans[i]=-1;
            }else{
                ans[i]=arr[s.top()];
            }
            s.push(i);
        }

        for(int i=0; i<ans.size(); i++){
            cout<<ans[i]<<" ";
        }
}

int main(){
    vector<int> arr={4,3,8,9,5};
    vector<int> ans={0,0,0,0,0};

    NextGreaterNumber(arr,ans);

    return 0;
}