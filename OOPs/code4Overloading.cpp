// compile time overloading 
#include<iostream>
using namespace std;

//Constructor Overloading
class Student{
    public:
    string name;
 
    Student(){
        cout<<"non parameterized"<<endl;
    }
    Student(string name){
        cout<<"parameterized"<<endl;
        this->name=name;
    }
};

//function overloading
class Print{
    public:

    void show(int x){
        cout<<"int : "<<x<<endl;
    }

    void show(char ch){
        cout<<"char : "<<ch<<endl;
    }
};
int main(){

    Student s1;
    Student s2("Rahul");

    Print p;
    p.show(10);
    p.show('A');

    return 0;
}