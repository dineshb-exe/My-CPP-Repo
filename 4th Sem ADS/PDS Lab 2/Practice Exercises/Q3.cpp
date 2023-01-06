#include<iostream>
using namespace std;

class dummy{
    double d;
public:
    dummy(double x){
        d=x;
    }
    double getx(){
        return d;
    }
    double operator+(dummy& a){
        return a.getx()+d;
    }
    double operator-(dummy& a){
        return d-a.getx();
    }
    double operator*(dummy& a){
        return a.getx()*d;
    }
    double operator/(dummy& a){
        return d/a.getx();
    }
};


int main(){
     dummy a(12.4);
     dummy b(45.3);
    int ch;
    do{
        cout<<"Enter 1 to perform addition\nEnter 2 to perform subtraction\nEnter 3 to perform multiplication\nEnter 4 to perform division\nEnter 5 to quit";
        cin>>ch;
        if(ch==1){
            cout<<a+b<<endl;
        }
        else if(ch==2){
            cout<<a-b<<endl;
        }
        else if(ch==3){
            cout<<a*b<<endl;
        }
        else if(ch==4){
            cout<<a/b<<endl;
        }
    }while(ch>0&&ch<5);
}

