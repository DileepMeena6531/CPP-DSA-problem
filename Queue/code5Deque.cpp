// Deque STL

#include <iostream>
#include <deque>
using namespace std;

int main(){
    deque<int> d;
    d.push_front(2);
    d.push_front(1);
    d.push_back(3);
    d.push_back(4);

    //1 2 3 4
    cout<<"front "<<d.front()<<endl; //1
    cout<<"back "<<d.back()<<endl; // 4

    d.pop_front();
    d.pop_back();

    //2 3

    cout<<"front "<<d.front()<<endl; // 2
    cout<<"back "<<d.back()<<endl; // 3


    return 0;
}