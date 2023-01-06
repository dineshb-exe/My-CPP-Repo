#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;

struct Node{
    int data;
    Node* next;
};
Node* top=0;

void Push(int v){
    Node *n = new Node;
    n->data=v;
    n->next=top;
    top=n;
}

void POP(int &v){
    if(top){
        Node *n=top;
        v= n->data;
        top=n->next;
        delete n;
    }
    else
        cerr<<"STACK EMPTY!! ";
}
int isprime(int a){
    int i=2;
    int ch=1;
    while(i<a&&ch==1){
        if(a%i==0)
            ch=0;
        i++;
    }
    return ch;
}

void write_prime(int a,int b){
    int j;
    fstream f1("Primes.txt",ios::in|ios::out);
    for(j=a;j<=b;j++){
        if(isprime(j))
            f1<<j<<endl;
    }
    f1.close();
}


int main(){
    int ll,ul;
    cin>>ll;
    cin>>ul;

    int b,temp;
    fstream f2("Primes.txt",ios::in|ios::out);

        while(!f2.eof()){
        f2>>b;
        cout<<b<<" ";
        temp=b;
        while(temp>10)
            temp/=10;
        if(temp%2==0){
            Push(b);
            cout<<"*";
        }
}
    int c;
    while(top){
        POP(c);
        cout<<c<<endl;
    }
    f2.close();
}

