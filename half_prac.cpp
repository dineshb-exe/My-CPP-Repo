#include<iostream>
#include<fstream>

using namespace std;

struct Node{
    int data;
    Node* next;
    Node(){
        next=0;
    }
};
Node *f=0;
Node *r=0;

int QEmp(){
    return(!f);
}

void Qins(int v){
    Node* tmp = new Node;
    if(tmp){
            tmp->data=v;
            if(f==0)
            f=r=tmp;
            else{
                r->next=tmp;
                r=tmp;
            }
    }
    else
        cerr<<"QUEUE FULL";
}

void Qdel(int &valu){

    if(f){
        Node* tmp=f;
        valu=tmp->data;
        f=tmp->next;
        if(f==0)
            r=0;


        delete tmp;

    }
    else{
        cerr<<"QUEUE EMPTY";

    }

}
int isperfect(int x){
    int i=1,sum=0;
    while(i<x){
        if(x%i==0)
            sum+=i;
        i++;
    }
    return(sum==x);
}

int isprime(int &x){
    int i=2,ch=1;
    while(i<x&&ch==1){
        if(x%i==0)
        ch=0;
        i++;
    }
    return ch;
}

int main(){
    int a;
    ifstream f1("Numbers.dat",ios::binary);
    while(f1.read((char*)&a,sizeof(int))){

        Qins(a);
        cout<<"*";
    }
    f1.close();
    int nop=0,nopr=0;
    ofstream f2("Numbers2.txt");
    cin.get();
    int u;
    while(QEmp()==0){
        Qdel(u);
        if(isperfect(u)==1)
        nop++;
        if(isprime(u)==1)
        nopr++;
        cout<<"*";
    }
    f2<<"Number of Perfect Numbers: ";
    f2<<nop;
    f2<<"Number of prime numbers: ";
    f2<<nopr;
    f2.close();
}
