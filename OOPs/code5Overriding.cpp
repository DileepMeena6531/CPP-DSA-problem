// Run time polymorphism
#include<iostream>
using namespace std;

//function Overriding
class Parent{
    public:

    void getInfo(){
        cout<<"This is Parent class"<<endl;
    }

    virtual void hello(){
        cout<<"hello in parent class"<<endl;
    }
};

class Child:public Parent{
    public:

    void getInfo(){
        cout<<"This is Child class"<<endl;
    }

    void hello(){
        cout<<"hello in child class"<<endl;
    }
};
int main(){
    Child c1;
    c1.getInfo();

    c1.hello();
    return 0;
}