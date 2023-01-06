#include<iostream>
using namespace std;
class flight{
    int flight_no;
    string source;
    string destination;
    int fare;
public:
    flight(){
        this->flight_no=1;
        this->source = "Chennai";
        this->destination = "Mumbai";
        this->fare = 3500;
    }
    void display(){
        cout<<"Flight No.: "<<this->flight_no<<endl;
        cout<<"Source Location: "<<this->source<<endl;
        cout<<"Destination: "<<this->destination<<endl;
        cout<<"Fare: "<<this->fare<<endl;
    }
};
int main(){
    flight f;
    f.display();
}
