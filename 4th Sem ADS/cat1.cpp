#include<iostream>
using namespace std;
void f(int a){
    cout<<a;
}
int f(int a, int b){
    cout<<a<<b;
    return (a+b);
}
float f(float a, float b){
    cout<<a<<b;
    return (a+b);
}
int main(){
    f(2);
    f(2,3);
    f(float(2.5),float(1.5));
}
