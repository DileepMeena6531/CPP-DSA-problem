#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

void countSort(int *arr, int n){

    int freq[1000]={0};
    int maxValue=INT_MIN, minValue=INT_MAX;

    for(int i=0; i<n; i++){
        freq[arr[i]]++;
        maxValue=max(maxValue,arr[i]);
        minValue=min(minValue,arr[i]);
    }

    for(int i=minValue,j=0; i<=maxValue; i++){
            while(freq[i]>0){
                arr[j++]=i;
                freq[i]--;
            }
    }

}
int main(){

    int arr[]={5,7,4,6,3,8,1,28,23,1,7};
    // int arr[]={5,4,3,2,1};
    int n=sizeof(arr)/sizeof(arr[0]);

    countSort(arr,n);

    print(arr,n);

    return 0;
}