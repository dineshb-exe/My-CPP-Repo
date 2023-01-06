#include<iostream>
using namespace std;

class Person{
protected:
    Person(){
        cout<<"Person Created!!! ";
    }
};

class Student: public Person{
protected:
    Student(){
        cout<<"A person has become a student! ";
    }
};
class Topper: public Student{
public:
    Topper(){
        cout<<"The hard work put up by the student has made him/her a topper!!! ";
    }
};

int main(){
    Topper t1;
    cout<<endl;
}
