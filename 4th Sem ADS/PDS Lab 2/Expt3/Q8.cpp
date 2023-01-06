#include<iostream>
using namespace std;
int main(){
    int* a;
    char* b;
    float* c;
    a= new int;
    b=new char;
    c= new float[5];
    cout<<"Enter the value for a: ";
    cin>>*a;
    cout<<"Enter the value for b: ";
    cin>>*b;
    cout<<"Enter the values for c: \n";
    int i;
    for(i=0;i<5;i++){
        cout<<"Enter the value for "<<" element "<<i+1<<" of c: ";
        cin>>c[i];
    }
    cout<<*a<<endl;
    cout<<*b<<endl;
    for(i=0;i<5;i++){
        cout<<c[i]<<endl;
    }
    delete a;
    delete b;
    delete[] c;
}
