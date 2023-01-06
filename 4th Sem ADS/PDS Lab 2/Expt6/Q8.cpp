#include<iostream>
using namespace std;
template <typename dt>
void search1(dt* arr, int s, dt n){
    int ch=1,i;
    for(i=0;i<s&&ch==1;i++){
        if(arr[i]==n){
            cout<<"Element Found!! "<<endl;
            ch=0;
        }
    }
}
template <typename dt>
void search2(dt* arr, int s, dt n){
    int l=0;
    int h=s-1;
    int mid=(l+h)/2;
    int ch=1;
    while(ch==1){
        if(arr[mid]==n){
            cout<<"Element Found "<<endl;
            ch=0;
        }
        else if(arr[mid]>n){
            l=mid+1;
            mid=(l+h)/2;
        }
        else{
            h=mid-1;
            mid=(l+h)/2;
        }
        if(h==mid){
            ch=0;
        }
    }
}

int main(){
    double* a;
    int *b;
    int n,i;
    cout<<"Enter n: ";
    cin>>n;
    a=new double[n];
    b=new int[n];
    for(i=0;i<n;i++){
        cout<<"Enter an element for the first array: ";
        cin>>a[i];
        cout<<"Enter an element for the second array: ";
        cin>>b[i];
    }
    double key;
    cout<<"Enter the value to be searched in the first array: ";
    cin>>key;
    int k2;
    cout<<"Enter the value to be searched in the second array: ";
    cin>>k2;
    search1(a,n,key);
    search1(b,n,k2);
    delete[] a;
    delete[] b;
}
