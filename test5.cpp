#include<iostream>
using namespace std;
int main(){
    int a=10;
    int c;
    c=(((a++)++)+a++)+a+a;
    cout<<c<<a;
}
