#include<iostream>
#include<vector>
#include<stack>
using namespace std;
void areaOfHestogram(vector<int> Height){
    int n=Height.size();
    vector<int> nsl(n);
    vector<int> nsr(n);
    stack<int> s;
    s.push(0);
    nsl[0]=-1;
    // left next smaller value
    for(int i=1; i<n; i++){
        
        while(!s.empty() && Height[i]<=Height[s.top()]){
            s.pop();
        }
        if(s.empty()){
            nsl[i]=-1;
        }else{
            nsl[i]=s.top();
        }
        s.push(i);
    }

    while(!s.empty()){
        s.pop();
    }

    //next right smaller value
    s.push(n-1);
    nsr[n-1]=n;
    for(int i=n-2; i>=0; i--){

        while(!s.empty() && Height[i]<=Height[s.top()]){
            s.pop();
        }

        if(s.empty()){
            nsr[i]=n;
        }else{
            nsr[i]=s.top();
        }
        s.push(i);
    }

    int maxArea=0;

    for(int i=0; i<n; i++){
        int width=nsr[i]-nsl[i]-1;
        int area=width*Height[i];
        maxArea=max(maxArea,area);
    }

    cout<<"area of Hestogram "<<maxArea<<endl;

}

int main(){
    vector<int> Height={5,4,3,2,4,4,4,4,4};

    areaOfHestogram(Height);

    return 0;
}