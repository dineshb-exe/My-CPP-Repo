#include<iostream>
using namespace std;

class Mammals{
public:
    void display1(){
        cout<<"I am mammal "<<endl;
    }
};

class MarineAnimals{
public:
    void display2(){
        cout<<"I am a marine animal "<<endl;
    }
};

class BlueWhale:public Mammals,public MarineAnimals{
public:
    void display3(){
        cout<<"I belong to both the categories: Mammals as well as Marine Animals"<<endl;
    }
};
int main(){
    Mammals m1;
    MarineAnimals ma1;
    BlueWhale b1;
    m1.display1();
    ma1.display2();
    b1.display3();
    b1.display1();
    b1.display2();
}
