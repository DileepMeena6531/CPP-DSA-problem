#include<iostream>
#include<vector>
using namespace std;

void heapify(int i,vector<int> &v,int n){
    int l=2*i+1;
    int r=2*i+2;
    int maxI=i;
    if(l<n && v[l]>v[maxI]){
        maxI=l;
    }
    if(r<n && v[r]> v[maxI]){
        maxI=r;
    }

    if(maxI!=i){
        swap(v[maxI],v[i]);
        heapify(maxI,v,n);
    }

}

void heapSort(vector<int> &v){
    int n=v.size();

    for(int i=n/2-1; i>=0; i--){
        heapify(i,v,n);
    }

    for(int i=n-1; i>=0; i--){
        swap(v[0],v[i]);
        heapify(0,v,i);
    }
}
int main(){
    vector<int> v={1,2,5,4,3};
    heapSort(v);

    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;

    return 0;
}