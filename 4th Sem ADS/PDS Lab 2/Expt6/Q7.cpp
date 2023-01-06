#include<iostream>
#include<exception>
using namespace std;

int multiply(int x, double y){
    int z=x*y;
    double z2=x*y;
    if(z!=z2)
        throw "Implicit Conversion Detected!!";
    return z;
}
int main(){
    int a;
    double b;
    cout<<"Enter a: ";
    cin>>a;
    cout<<"Enter b: ";
    cin>>b;
    try{
         cout<<multiply(a,b);
    }
    catch(const char* s){
        cerr<<s<<endl;
    }
}
