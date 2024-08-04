#include<iostream>
#include<list>
#include<iterator>
using namespace std;

void print(list<int> ll){
    list<int>::iterator itr;

    for(itr=ll.begin(); itr!=ll.end(); itr++){
            cout<<(*itr)<<"->";
    }
    cout<<"NULL"<<endl;
}

int main(){
    list<int> ll;
    ll.push_front(1);
    ll.push_front(2);
    ll.push_back(3);
    ll.push_back(4);

    print(ll);

    cout<<"size of ll "<<ll.size()<<endl;
    cout<<"head of ll "<<ll.front()<<endl;
    cout<<"tail of ll "<<ll.back()<<endl;

    list<int>::iterator it=ll.end();

    ll.insert(it,2,7);
    // ll.assign(2,5);
    print(ll);



    return 0;
}