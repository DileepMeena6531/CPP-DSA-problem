#include<iostream>
#include<vector>
using namespace std;

void merge(int *arr,int s,int mid,int e){
    int i=s;
    int j=mid+1;
    vector<int> temp;

    while(i<=mid and j<=e){
        if(arr[i]<arr[j]){
            temp.push_back(arr[i++]);
        }else{
            temp.push_back(arr[j++]);
        }
    }

    while(i<=mid){
        temp.push_back(arr[i++]);
    }
    while(j<=e){
        temp.push_back(arr[j++]);
    }

    for(int z=s,k=0; z<=e; z++){
        arr[z]=temp[k++];
    }
}

void mergeSort(int *arr,int s,int e){
    if(s>=e){
        return;
    }

    int mid=s+(e-s)/2;
    mergeSort(arr,s,mid);
    mergeSort(arr,mid+1,e);
    merge(arr,s,mid,e);
}
int main(){

    int arr[]={5,2,4,7,1,2,7,3};
    int n=sizeof(arr)/sizeof(arr[0]);

    mergeSort(arr,0,n-1);

    for(int i=0; i<8; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}