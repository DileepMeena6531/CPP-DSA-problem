#include<iostream>
#include<vector>
using namespace std;
void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

void selectionSort(int *arr, int n){

    for(int i=0; i<n-1; i++){
        int min=i;
        for(int j=i+1; j<n; j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        swap(arr[i],arr[min]);
    }
}
int main(){

    // int arr[]={5,7,4,6,3,8,1,2};
    int arr[]={5,4,3,2,1};
    int n=sizeof(arr)/sizeof(arr[0]);

    selectionSort(arr,n);

    print(arr,n);

    return 0;
}