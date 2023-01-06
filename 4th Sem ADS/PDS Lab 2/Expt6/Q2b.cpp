#include<iostream>
using namespace std;
template <typename T>

void Sort(T* arr,int s){
    for(int i=0;i<s;i++){
        int min_index=i;
        for(int j=i+1;j<s;j++){
            if(arr[j]<arr[min_index]){
                min_index=j;
            }
        }
        T temp=arr[i];
        arr[i]=arr[min_index];
        arr[min_index]=temp;
    }
}
int main(){
    double* d;
    int* a;
    int n;
    cout<<"Enter the number of elements in each list: ";
    cin>>n;
    d=new double[n];
    a=new int[n];
    for(int i=0;i<n;i++){
        cout<<"Enter a value: ";
        cin>>d[i];
    }
    for(int i=0;i<n;i++){
        cout<<"Enter a value: ";
        cin>>a[i];
    }
    cout<<"List 1 before Sorting: ";
    for(int i=0;i<n;i++){
        cout<<d[i]<<"\t";
    }
    cout<<endl;
    Sort(d,n);
    cout<<"List 1 after Sorting: ";
    for(int i=0;i<n;i++){
        cout<<d[i]<<"\t";
    }
    cout<<endl;

    cout<<"List 2 before sorting: ";
    for(int i=0;i<n;i++){
        cout<<a[i]<<"\t";
    }
    cout<<endl;
    Sort(a,n);
    cout<<"List 2 before sorting: ";
    for(int i=0;i<n;i++){
        cout<<a[i]<<"\t";
    }
    cout<<endl;
    delete[] d;
    delete[] a;
}
