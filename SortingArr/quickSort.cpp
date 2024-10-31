#include<iostream>
#include<vector>
using namespace std;

int quick(int *arr,int s,int e){
    int i=s-1;
    int j=s;
    while(j<=e){
        if(arr[j]<arr[e]){
            i++;
            swap(arr[i],arr[j]);
        }
        j++;
    }
    swap(arr[i+1],arr[e]);
    return i+1;
}

void quickSort(int *arr,int s,int e){
    if(s>=e){
        return;
    }

    int piovt=quick(arr,s,e);
    quickSort(arr,s,piovt-1);
    quickSort(arr,piovt+1,e);
}

int main(){
    int arr[]={6,3,5,4,2,3,17,5};
    int n=sizeof(arr)/sizeof(arr[0]);

    quickSort(arr,0,n-1);

    for(int i=0; i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}