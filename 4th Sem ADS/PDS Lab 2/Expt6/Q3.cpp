#include<iostream>
#include<exception>
using namespace std;
int intDivEx(int numerator, int denominator){
    if(denominator==0)
        throw overflow_error("Divide by 0 exception");
    return numerator/denominator;
}
int main(){
    int a,b;
    cout<<"Enter the numerator: ";
    cin>>a;
    cout<<"Enter the denominator: ";
    cin>>b;
    cout<<intDivEx(a,b);
}
