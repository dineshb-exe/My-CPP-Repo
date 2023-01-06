#include<iostream>
#include<iomanip>
using namespace std;

class time_{
    int h;
    int m;
    int s;
    public:
        void read(){
            cout<<"Enter hr part of the time: ";
            cin>>h;
            cout<<"Enter minute part of the time: ";
            cin>>m;
            cout<<"Enter seconds part of the time: ";
            cin>>s;
        }
        void display(){

            cout<<"The time is: "<<setw(2)<<setfill('0')<<h<<":"<<setw(2)<<setfill('0')<<m<<":"<<setw(2)<<setfill('0')<<s;
        }
};

int main(){
    time_ t1;
    t1.read();
    t1.display();
}
