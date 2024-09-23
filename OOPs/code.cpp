#include<iostream>
using namespace std;
class Teacher{
    private:
    double salary;

    public:
    string name;
    int age;
    string subject;
    string dept;

    //non-parameterized constructor
    Teacher(){
        dept="english";
    } 

    //parameterized constructor
    Teacher(string name,int age,string subject,string dept,double salary){
        this->name=name;
        this->age=age;
        this->dept=dept;
        this->subject=subject;
        this->salary=salary;
    }

    //copy constructor 
    Teacher(Teacher &orgObj){
        this->name=orgObj.name;
        this->age=orgObj.age;
        this->subject=orgObj.subject;
        this->salary=orgObj.salary;
    }

    void getInfo(){
        cout<<"name : "<<name<<endl;
        cout<<"age : "<<age<<endl;
        cout<<"subject : "<<subject<<endl;
        cout<<"salary :"<<salary<<endl;
    }

    void changeDep(string newDep){
        dept=newDep;
    }

    //setter
    void setSalary(double s){
        salary=s;
    }
    //getter
    double getSalary(){
        return salary;
    }

};
int main(){
    Teacher t1;
    t1.name="dileep";
    t1.age=25;
    t1.subject="maths";
    t1.dept="chemical";
    // t1.salary=50000;  this give erro becouse private so we use getter setter

    t1.setSalary(50000);

    cout<<t1.name<<" "<<t1.dept<<endl;
    cout<<t1.getSalary()<<endl;

    // t1.changeDep("computer science");

    cout<<t1.dept<<endl;

    Teacher t2("rahul",21,"math","civil",5000);

    // t2.getInfo();

    // copy constructor
    Teacher t3(t2);
    t3.getInfo();

    return 0;
}