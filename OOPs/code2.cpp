//shallow and deep copy
#include<iostream>
using namespace std;
class Student{
    public:
    string name;
    double *cgpaPtr; // memory address 

    Student(string name,double cgpa){
        this->name=name;
        cgpaPtr=new double; // point toward the memory address
        *cgpaPtr=cgpa; // in memory address we put value cgpa
    }

    // copy constructor
    Student(Student &obj){
        this->name=obj.name;
        cgpaPtr=new double;
        *cgpaPtr=*obj.cgpaPtr;
    }

    void getInfo(){
        cout<<"Name: "<<name<<endl;
        cout<<"CGPA: "<<*cgpaPtr<<endl;
    }
};
int main(){
    Student s1("dileep",8.6);
    s1.getInfo();

    // shallow copy
    Student s2(s1);
    *(s2.cgpaPtr)=9.2;
    s2.name="rahul";

    s1.getInfo();

    s2.getInfo();

    return 0;
}