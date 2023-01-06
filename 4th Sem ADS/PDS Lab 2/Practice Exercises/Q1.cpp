#include<iostream>
using namespace std;

class SSNCoin{
    int val;
    long int cash;//The cash equivalent of val in rupees
public:
    SSNCoin(){
        val=0;
    }
    void deposit(int v){
        val=v;
    }
    void withdraw(int v){
        if(v>val){
            cout<<"Amount cannot be withdrawn!\n";
        }
        else{
            val=val-v;
            cout<<"Amount withdrawn! \n";
        }
    }
    void transfer(SSNCoin x,int c){
        if(c>val){
            cout<<"Cannot be transferred\n";
        }
        else{
            val=val-c;
            x.deposit(c);
        }
    }
    void convert_into_cash(){
        cash=val*42501;
    }
    void disp_cash(){
        cout<<"The cash equivalent of value in the account: "<<cash<<endl;
    }
};
int main(){
    SSNCoin s1,s2;
    int ch;
    cout<<"Welcome to SSNCoin Management System\n";
    do{
        cout<<"Enter 1 to deposit SSNCoin\nEnter 2 to withdraw SSNCoin\nEnter 3 to transfer SSNCoin from one account to another\nEnter 4 to display the cash equivalent of the value in the account\nEnter 5 to exit\n";
        cin>>ch;
        if(ch==1){
            int v;
            cout<<"Enter the value to be deposited ";
            cin>>v;
            s1.deposit(v);
        }
        else if(ch==2){
            int v;
            cout<<"Enter the value to be withdrawn ";
            cin>>v;
            s1.withdraw(v);
        }
        else if(ch==3){
            int v;
            cout<<"Enter the value to be transferred: ";
            cin>>v;
            s1.transfer(s2,v);
        }
        else if(ch==4){
            s1.convert_into_cash();
            s1.disp_cash();
        }
        else if(ch>5){
            cout<<"Invalid Input! Enter the correct choice again\n";
            ch=1;
        }
    }while(ch>0&&ch<5);
}

