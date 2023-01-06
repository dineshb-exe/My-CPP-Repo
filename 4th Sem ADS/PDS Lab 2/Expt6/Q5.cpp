#include<iostream>
#include<string>
using namespace std;
class person{
    long aadhar_num;
    public:
    virtual void getdata() {
        cout<<"Enter your Aadhaar number:";
        cin>>aadhar_num;
        cin.get();
    }
    virtual void display() {
        cout<<"Aadhaar Card Number: "<<aadhar_num<<endl;
    }
    virtual void bonus () {
        cout<<"Bonus Function from class person: "<<endl;
    }
};
class admin : public virtual person{
    int sales;
public:
    void getdata(){
        cout<<"Enter the Sales amount by the admin: ";
        cin>>sales;
    }
    void display(){
        cout<<"Sales amount for Admin:"<<sales<<endl;
    }
    void bonus(){
        if(sales>1080)
        cout<< "Bonus for Admin: "<<sales* 0.25<<endl;
    }
};
class account:public virtual person {
    long int amt;
    public :
    void getdata(){
        cout<<"Enter the amount in the account : ";
        cin>>amt;
    }
    void display(){
        cout <<"Amount present in account: "<<amt<<endl;
    }
    void bonus() {
        cout<<"Bonus amount in the account: "<<amt*0.25;
    }
};
class master: public admin, public account{
public:
    void getdata(){
        cout <<"\n Executing getdata of master class : ";
        person::getdata();
        admin::getdata();
        account::getdata();
    }
    void display(){
        cout <<"\n Display from Master Class ";
        person::display();
        admin::display();
        account::display();
    }
    void bonus(){
        cout <<"\n Bonus Function: \n";
        person:: bonus();
        admin:: bonus();
        account:: bonus ();
    }
};
int main(){
    person p, *pptr;
    admin a, *aptr;
    account ac, *acptr;
    master m, *mptr;
    pptr=&p;
    pptr->getdata();
    pptr->display();
    pptr->bonus();
    pptr=&a;
    pptr->getdata();
    pptr->display();
    pptr->bonus ();
    pptr=&ac;
    pptr->getdata();
    pptr->display();
    pptr->bonus ();
    pptr=&ms;
    pptr->getdata();
    pptr->display();
    pptr->bonus ();
}
