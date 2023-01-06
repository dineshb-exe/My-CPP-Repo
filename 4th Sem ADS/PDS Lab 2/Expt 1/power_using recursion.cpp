#include<iostream>
using namespace std;

int power(int n,int p){
    if(p==1){
        return n;
    }
    else{
        return n*power(n,p-1);
    }
}
int main(){
    int num;
    cout<<"Enter a number: ";
    cin>>num;
    int pow;
    cout<<"Enter the power to which the numbe should be raised: ";
    cin>>pow;
    cout<<num<<" power "<<pow<<" equals: "<<power(num,pow);
}
