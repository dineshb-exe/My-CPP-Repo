#include<iostream>
using namespace std;

const int N=10;

int Sum(int a,int b=100){
    int s;
    s=a+b;
    return s;
}

int main(){
    int *a, n;
    cout<<"Enter the number of elements to be allocated for the array: ";
    cin>>n;
    a=new int[n];
    int i;
    for(i=0;i<n;i++){
        cout<<"Enter a number: ";
        cin>>a[i];
    }
    cout<<"The array before computation of sum: ";
    for(i=0;i<n;i++){
        cout<<a[i]<<"\t";
    }
    for(i=0;i<n;i++){
        if(a[i]%2==0)
        a[i]=Sum(a[i],i%n);//Each element having an odd value is incremented by it's index value mod n
        else
        a[i]=Sum(a[i]);//Each element having an even value is incremented by 100
    }
    cout<<endl;
    cout<<"The array after computation of sum: ";
    for(i=0;i<n;i++){
        cout<<a[i]<<"\t";
    }
    delete []a;
}
