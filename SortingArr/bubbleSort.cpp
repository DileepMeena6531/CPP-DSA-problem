#include<iostream>
#include<vector>
using namespace std;
void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

void bubbleSort(int *arr, int n){

    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
int main(){

    // int arr[]={5,7,4,6,3,8,1,2};
    int arr[]={5,4,3,2,1};
    int n=sizeof(arr)/sizeof(arr[0]);

    bubbleSort(arr,n);

    print(arr,n);

    return 0;
}