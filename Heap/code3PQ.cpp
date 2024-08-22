#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class student{
    public:
    string name;
    int marks;
    student(string name,int marks){
        this->name=name;
        this->marks=marks;
    }

    // operator overload
    bool operator < (const student &obj) const{
        return marks < obj.marks;
    } 
};
int main(){
    priority_queue<student> h;
    h.push(student("dileep",85));
    h.push(student("aman",78));
    h.push(student("sunny",92));

    while(!h.empty()){
        cout<<"name: "<<h.top().name<<", "<<h.top().marks<<endl;
        h.pop();
    }

    return 0;
}