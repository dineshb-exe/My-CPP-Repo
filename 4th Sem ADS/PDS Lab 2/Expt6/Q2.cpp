#include<iostream>
using namespace std;
template <typename T>

void MinMax(T* a, int n){
    T min1=a[0];
    T max1=a[0];
    for(int i=0;i<n;i++){
        if(a[i]>max1)
            max1=a[i];
        if(a[i]<min1)
            min1=a[i];
    }
    cout<<"The maximum value in the list: "<<min1<<endl;
    cout<<"The maximum value in the list: "<<max1<<endl;
}
int main(){
    double *a;
    int *b;
    int s;
    cout<<"Enter the number of values to be stored in the list: ";
    cin>>s;
    a=new double[s];
    b=new int[s];
    for(int i=0;i<s;i++){
        cout<<"Enter a value: ";
        cin>>a[i];
    }
    for(int i=0;i<s;i++){
        cout<<"Enter a value: ";
        cin>>b[i];
    }
    MinMax(a,s);
    MinMax(b,s);
    delete[] b;
    delete[] a;
}
