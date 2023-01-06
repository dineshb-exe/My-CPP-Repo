#include<iostream>
using namespace std;
class distance_{
    int km;
    int m;
    public:
    distance_(){
        km=0;
        m=0;
    }
    void input(){
        cout<<"Enter the km part of the distance: ";
        cin>>km;
        cout<<"Enter the m part of the distance: ";
        cin>>m;
    }
    void display(){
        cout<<"The distance: "<<km<<"km "<<m<<"m"<<endl;
    }
    distance_ add(distance_ d){
        distance_ d3;
        d3.m=m+d.m;
        if(d3.m>1000){
            d3.km+=(d3.m+m)/1000;
            d3.m-=(d3.km*1000);
        }
        d3.km+=(km+d.km);
        return d3;
    }
};

int main(){
    distance_ d1,d2,res;
    d1.input();
    d2.input();
    res=d1.add(d2);
    cout<<"Distance 1: ";
    d1.display();
    cout<<"Distance 2: ";
    d2.display();
    cout<<"Addition of 2 distances: ";
    res.display();
}
