#include<iostream>
using namespace std;

class rectangle{
private:
    int l;
protected:
    int b;
public:
    rectangle(){
        l=1;
        b=1;
    }
    rectangle(int l1,int b1){
        l=l1;
        b=b1;
    };
    friend int calcarea(rectangle& r);
};

int calcarea(rectangle& r){
    int area=r.l*r.b;
    return area;
}
int main(){
    rectangle r1(23,16);
    cout<<"Area of Rectangle: "<<calcarea(r1);
}
