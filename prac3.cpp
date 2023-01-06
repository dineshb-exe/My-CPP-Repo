#include<iostream>
#include<fstream>
#include<string.h>
#include<iomanip>

using namespace std;

void swap1(int &a,int &b){
    a+=b;
    b=a-b;
    a-=b;
}

void Bubble_Sort(int *a,int len){
    for(int i=len-1;i>0;i--){
        for(int j=0;j<i;j++){
            if(a[j]>a[j+1])
                swap1(a[j],a[j+1]);
        }
    }
}

void RBubble_Sort(int *a,int len){
    for(int i=len-1;i>0;i--){
        for(int j=0;j<i;j++){
            if(a[j]<a[j+1])
                swap1(a[j],a[j+1]);
        }
    }

}
int main(){
    int N;
    cout<<setw(50)<<"ENTER THE VALUE OF NUMBER OF ELEMENTS IN THE ARRAY:\n";
    cout<<setw(50);
    cin>>N;
    int *ARR=new int[N];
    for(int i=0;i<N;i++){
        cout<<"Enter the number";
        cin>>ARR[i];
    }
    char c;
    cout<<"Enter A if the array is to be arranged in ascending order\n Enter D for descending order";
    cin>>c;
    if(c=='A'||c=='a')
    Bubble_Sort(ARR,N);
    else if(c=='D'||c=='d')
        RBubble_Sort(ARR,N);
    for(int j=0;j<N;j++){
        cout<<ARR[j];
    }
}

