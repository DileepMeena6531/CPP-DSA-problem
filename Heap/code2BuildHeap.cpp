#include<iostream>
#include<vector>
using namespace std;
class Heap{
    vector<int> v;
    public:

    void push(int val){
        v.push_back(val);
        int childInd=v.size()-1;
        int parInd=(childInd-1)/2;
        while(parInd>=0 && v[childInd] > v[parInd]){
            swap(v[childInd],v[parInd]);
            childInd=parInd;
            parInd=(childInd-1)/2;  
        }
    }
    void heapify(int i){
        if(i>=v.size()){
            return;
        }

        int l=(2*i+1);
        int r=(2*i+2);
        int maxI=i;

        if(l<v.size() && v[l]>v[maxI]){
            maxI=l;
        }
        if(r<v.size() && v[r]>v[maxI]){
            maxI=r;
        }
        
        swap(v[i],v[maxI]);
        if(maxI!=i){
            heapify(maxI);
        }

    }

    void pop(){
        swap(v[0],v[v.size()-1]);
        v.pop_back();
        heapify(0);
    }

    int top(){
        return v[0];
    }

    bool empty(){
        return v.size()==0;
    }
};

int main(){
    Heap h;
    h.push(8);
    h.push(4);
    h.push(5);
    h.push(4);
    h.push(1);
    h.push(2);
    
    while(!h.empty()){
        cout<<h.top()<<" ";
        h.pop();
    }


    return 0;
}