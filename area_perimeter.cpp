#include<iostream>
#include<math.h>
#define pi 3.14
using namespace std;
int main(){
    float r;
    cout<<"Enter the radius: ";
    cin>>r;
    cout<<"Area: "<<pi*pow(r,2)<<"\nPerimeter: "<<2*pi*r;
}
