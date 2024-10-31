#include<iostream>
#include<vector>
using namespace std;
void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

void insertionSort(int *arr, int n){

    for(int i=1; i<n; i++){
        int curr=arr[i];
        int j=i-1;
        while(j>=0 and arr[j]>curr){
            swap(arr[j],arr[j+1]);
            j--;
        }
    }
      
}
int main(){

    int arr[]={5,7,4,6,3,8,1,2};
    // int arr[]={5,4,3,2,1};
    int n=sizeof(arr)/sizeof(arr[0]);

    insertionSort(arr,n);

    print(arr,n);

    return 0;
}