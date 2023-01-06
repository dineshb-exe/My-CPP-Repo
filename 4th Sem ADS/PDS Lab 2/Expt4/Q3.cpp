#include<iostream>
using namespace std;

class Fruit{
protected:
    static int ct;
public:
    int getCount(){
        return ct;
    }
};

class Apples: public Fruit{
    int ca;
public:
    void setCount(int c){
        ca=c;
        ct+=ca;
    }
};

class Mangoes: public Fruit{
    int cm;
public:
    void setCount(int c){
        cm=c;
        ct+=cm;
    }
};

int Fruit::ct=0;

int main(){
    Apples a1;
    Mangoes m1;
    int c1;
    cout<<"Enter the  count of apples: ";
    cin>>c1;
    a1.setCount(c1);
    cout<<"Enter the count of mangoes: ";
    cin>>c1;
    m1.setCount(c1);
    cout<<"The total number of fruits in the basket is: "<<m1.getCount();
}
