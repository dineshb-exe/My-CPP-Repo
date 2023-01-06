#include<iostream>
#include<stdlib.h>

using namespace std;

int main(){
    int w;
    int a;
    cin>>w;
    a=rand()%w;
    if(w>=1&&w<=100){
        if(w%2!=0){
            cout<<"NO";
        }
        else if((w/2)<0){
            cout<<"NO";
        }

        else if(a%2==0&&(w-a)%2==0){
            cout<<"NO";
        }
        else
        cout<<"YES";
    }

}
