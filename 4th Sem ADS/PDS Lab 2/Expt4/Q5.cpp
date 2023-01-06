#include<iostream>
#include<string>
using namespace std;

class RBI{
protected:
    float min_int_rate;
    int min_balance;
    int max_withdrawal_limit;
public:
    RBI(){
        min_int_rate=4;
    }
};

class SBI: public RBI{
    int nob;
    int noc;
    int nationalised=1;
public:
    void setRate(){
        cout<<"Enter the minimum rate of interest: (should be>4) ";
        cin>>min_int_rate;
        if(min_int_rate<4)
            min_int_rate=4;
    }
    void read(){
        cout<<"Enter the minimum balance to be maintained: ";
        cin>>min_balance;
        cout<<"Enter the maximum withdrawal amount for an account in % of the total balance: ";
        cin>>max_withdrawal_limit;
        cout<<"Enter the number of branches: ";
        cin>>nob;
        cout<<"Enter the number of customers (in millions): ";
        cin>>noc;
    }
    void display(){
        cout<<"Minimum rate of interest: "<<min_int_rate<<endl;
        cout<<"Minimum balance to be maintained: "<<min_balance<<endl;
        cout<<"Maximum withdrawal amount in % of the total balance: "<<max_withdrawal_limit<<endl;
        cout<<"Number of branches: "<<nob<<endl;
        cout<<"Number of customers (in millions): "<<noc<<endl;
        if(nationalised==1)
        cout<<"This is a Nationalized bank "<<endl;
        else
        cout<<"This is a private bank "<<endl;
    }
};

class ICICI: public RBI{
    int nob;
    int noc;
    int nationalised=0;
public:
    void setRate(){
        cout<<"Enter the minimum rate of interest: (should be>4) ";
        cin>>min_int_rate;
        if(min_int_rate<4)
            min_int_rate=4;
    }
    void read(){
        cout<<"Enter the minimum balance to be maintained: ";
        cin>>min_balance;
        cout<<"Enter the maximum withdrawal amount for an account in % of the total balance: ";
        cin>>max_withdrawal_limit;
        cout<<"Enter the number of branches: ";
        cin>>nob;
        cout<<"Enter the number of customers (in millions): ";
        cin>>noc;
    }
    void display(){
        cout<<"Minimum rate of interest: "<<min_int_rate<<endl;
        cout<<"Minimum balance to be maintained: "<<min_balance<<endl;
        cout<<"Maximum withdrawal amount in % of the total balance: "<<max_withdrawal_limit<<endl;
        cout<<"Number of branches: "<<nob<<endl;
        cout<<"Number of customers (in millions): "<<noc<<endl;
        if(nationalised==1)
        cout<<"This is a Nationalized bank "<<endl;
        else
        cout<<"This is a private bank "<<endl;
    }
};

class PNB: public RBI{
    int nob;
    int noc;
    int nationalised=1;
public:
    void setRate(){
        cout<<"Enter the minimum rate of interest: (should be>4) ";
        cin>>min_int_rate;
        if(min_int_rate<4)
            min_int_rate=4;
    }
    void read(){
        cout<<"Enter the minimum balance to be maintained: ";
        cin>>min_balance;
        cout<<"Enter the maximum withdrawal amount for an account in % of the total balance: ";
        cin>>max_withdrawal_limit;
        cout<<"Enter the number of branches: ";
        cin>>nob;
        cout<<"Enter the number of customers (in millions): ";
        cin>>noc;
    }
    void display(){
        cout<<"Minimum rate of interest: "<<min_int_rate<<endl;
        cout<<"Minimum balance to be maintained: "<<min_balance<<endl;
        cout<<"Maximum withdrawal amount in % of the total balance: "<<max_withdrawal_limit<<endl;
        cout<<"Number of branches: "<<nob<<endl;
        cout<<"Number of customers (in millions): "<<noc<<endl;
        if(nationalised==1)
        cout<<"This is a Nationalized bank "<<endl;
        else
        cout<<"This is a private bank "<<endl;
    }
};

class Customer{
    string name;
    char addr[50];
    int phno;
    char sex;
    int age;
    string email;
public:
    void read2(){
        cout<<"Enter name of the customer: ";
        cin>>name;
        cin.get();
        cout<<"Enter the residential address of the customer: ";
        cin.getline(addr,50);
        cout<<"Enter the email ID of the customer: ";
        cin>>email;
        cin.get();
        cout<<"Enter the sex of the customer: ";
        cin>>sex;
        cout<<"Enter phone number of the customer: ";
        cin>>phno;
        cout<<"Enter the age of the customer: ";
        cin>>age;
        cin.get();
    }
    void display2(){
        cout<<"Name of the customer: ";
        cout<<name<<endl;
        cout<<"Residential address of the customer: ";
        cout<<addr<<endl;
        cout<<"Phone number of the customer: ";
        cout<<phno<<endl;
        cout<<"Sex of the customer: ";
        cout<<sex<<endl;
        cout<<"Age of the customer: ";
        cout<<age<<endl;
        cout<<"Email ID of the customer: ";
        cout<<email<<endl;
    }
};

class Account{
    int ac_no;
    int bal;
    int loan_taken;
    int col_value;
public:
    void read1(){
        cout<<"Enter the account number: ";
        cin>>ac_no;
        cout<<"Enter the balance amount in the account: ";
        cin>>bal;
        cout<<"Enter the amount of loan taken by the person: ";
        cin>>loan_taken;
        cout<<"Enter the value of collateral: ";
        cin>>col_value;
    }
    void display1(){
        cout<<"Account number: ";
        cout<<ac_no<<endl;
        cout<<"Balance amount in the account: ";
        cout<<bal<<endl;
        cout<<"Amount of loan taken by the person: ";
        cout<<loan_taken<<endl;
        cout<<"Value of collateral: ";
        cout<<col_value<<endl;

    }
};

int main(){
    SBI s1;
    ICICI i1;
    PNB p1;
    Customer c1;
    Account a1;
    s1.setRate();
    s1.read();
    s1.display();
    i1.setRate();
    i1.read();
    i1.display();
    p1.setRate();
    p1.read();
    p1.display();
    c1.read2();
    c1.display2();
    a1.read1();
    a1.display1();

}

