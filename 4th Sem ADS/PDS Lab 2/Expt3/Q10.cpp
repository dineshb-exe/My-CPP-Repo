#include<iostream>
using namespace std;

//Call by value example
void swap1(int a, int b){
    a+=b;
    b=a-b;
    a=a-b;
}
//Call by reference
void swap2(int& a, int& b){
    a+=b;
    b=a-b;
    a=a-b;
}

int main(){
    int x1,x2;
    cout<<"Enter the value of x1: ";
    cin>>x1;
    cout<<"Enter the value of x2: ";
    cin>>x2;
    swap1(x1,x2);
    cout<<"After processing the values through call by value function: \nx1 = "<<x1<<"\nx2 = "<<x2<<endl;
    swap2(x1,x2);
    cout<<"After processing the values through call by reference function: \nx1 = "<<x1<<"\nx2 = "<<x2<<endl;
}
