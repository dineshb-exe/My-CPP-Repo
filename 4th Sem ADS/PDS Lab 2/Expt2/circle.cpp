#include<iostream>
#define pi 3.14
using namespace std;

class circle{
    float r;
    float circumference;
    float area;

    public:
    void set_radius(int radius){
        r=radius;
    }
    float get_radius(){
        return r;
    }
    void calc_Circumference(){
        circumference=2*pi*r;
    }
    void calc_area(){
        area=pi*r*r;
    }
    float get_area(){
        return area;
    }
    float get_Circumference(){
        return circumference;
    }
};

int main(){
    circle c1;
    float r1;
    int ch;
    do{
        cout<<"Enter the radius for the circle: ";
        cin>>r1;
        c1.set_radius(r1);
        c1.calc_area();
        c1.calc_Circumference();
        cout<<"Area of the circle: "<<c1.get_area()<<endl;
        cout<<"Circumference of the Circle: "<<c1.get_Circumference();
        cout<<"\nDo you want to re-enter the radius? Enter 1 for Yes, 0 for No: ";
        cin>>ch;
    }
    while(ch);
}
