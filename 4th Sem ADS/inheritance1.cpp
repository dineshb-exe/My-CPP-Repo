#include<iostream>
using namespace std;
class Person{
    string name;
protected:
    int age;
    string getName(){
        return name;
    }
};

class Employee: private Person{
    int sal;
public:
    void display(){
        cout<<"Name: "<<getName()<<"\tAge: "<<age;
    }
};

int main(){
    Employee e1;
    e1.display();
}
