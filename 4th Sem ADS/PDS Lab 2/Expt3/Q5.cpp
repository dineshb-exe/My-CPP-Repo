#include<iostream>
using namespace std;

class circle{
    int radius;
public:
    friend void operator++(circle&c);
    friend void operator--(circle&c);
    circle(){
        radius = 5;
    }
    circle(int r){
        radius = r;
    }
    void display(){
        cout<<"Length of radius of a circle: "<<radius<<endl;
    }
};

void operator++(circle& c){
    ++c.radius;
}
void operator--(circle& c){
    --c.radius;
}
int main(){
    circle c1;
    c1.display();
    ++c1;
    c1.display();
    --c1;
    c1.display();
}
