#include<iostream>
#include<math.h>
using namespace std;

int main(){
    int p2,p1,con;
    cout<<"Enter the coefficient of the term with power 2: ";
    cin>>p2;
    cout<<"Enter the coefficient  of the term with power 1: ";
    cin>>p1;
    cout<<"Enter the value of the constant: ";
    cin>>con;
    int d=(p1*p1)-(4*p2*con);
    if(d<0){
        cout<<"No real roots!!!";
    }
    else if(d==0){
        cout<<"The roots are: "<<(-p1)/(p2*2)<<" , "<<(-p1)/(p2*2);
    }
    else{
        int x1=(-p1+sqrt(d))/(p2*2);
        int x2=(-p1-sqrt(d))/(p2*2);
        cout<<"The roots are: "<<x1<<" , "<<x2;
    }
}
