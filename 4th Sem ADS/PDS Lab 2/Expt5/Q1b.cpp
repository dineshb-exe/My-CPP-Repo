#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;
struct date{
    int day;
    int month;
    int year;
};

class Ticket_Reservation{
    int tid;
    char c_dep[21];
    char c_arr[21];
    char passenger_name[21];
    date doj;
public:
    Ticket_Reservation(){
        tid=-1;
        strcpy(c_dep,"Unknown");
        strcpy(c_arr,"Unknown");
        strcpy(passenger_name,"Unknown");
        doj.day=0;
        doj.month=0;
        doj.year=0;
    }
    void accept(){
        cout<<"Enter the Ticket ID: ";
        cin>>tid;
        cin.get();
        cout<<"Enter the city of departure: ";
        cin.getline(c_dep,21);
        cout<<"Enter the city of arrival: ";
        cin.getline(c_arr,21);
        cout<<"Enter the name of the passenger: ";
        cin.getline(passenger_name,21);
        cout<<"Enter the day of journey: ";
        cin>>doj.day;
        cout<<"Enter the month of journey: ";
        cin>>doj.month;
        cout<<"Enter the year of journey: ";
        cin>>doj.year;
    }
    void display(){
        cout<<"Ticket ID: "<<tid<<endl;
        cout<<"The city of departure: "<<c_dep<<endl;
        cout<<"The city of arrival: "<<c_arr<<endl;
        cout<<"The name of the passenger: "<<passenger_name<<endl;
        cout<<"The date of journey: "<<setw(2)<<setfill('0')<<doj.day<<"/"<<setw(2)<<setfill('0')<<doj.month<<"/"<<setw(4)<<setfill('0')<<doj.year<<endl;
    }
};

class node{
    Ticket_Reservation data;
    node* next;
public:
    node(){
        next=0;
    }
    void setData(Ticket_Reservation x){
        data=x;
    }
    void getData(){
        data.display();
    }
    node* getNext(){
        return next;
    }
    void enQ(Ticket_Reservation v);
    void deQ(Ticket_Reservation& v);
    void menu();
};

node* f=0;
node* r=0;

void node::enQ(Ticket_Reservation v){
    node* tmp=new node;
    if(tmp){
        tmp->data=v;
        tmp->next=0;
        if(f==0){
            f=r=tmp;
        }
        else{
            r->next=tmp;
            r=tmp;
        }
    }
    else{
        cout<<"Queue Full! "<<endl;
    }
}

void node::deQ(Ticket_Reservation& v){
    node* tmp=f;
    v=f->data;
    f=f->next;
    delete tmp;
    if(f==0)
        r=0;
    else{
        cout<<"Queue Empty!! "<<endl;
    }
}

void node::menu(){
    int ch;
    do{
        cout<<"Enter 1 to create a queue\nEnter 2 to enqueue an element\nEnter 3 to display elements\nEnter 4 to dequeue elements\nEnter 5 to delete queue\nEnter 6 to quit: ";
        cin>>ch;
        if(ch==1){
            if(f==0){
                Ticket_Reservation n;
                n.accept();
                enQ(n);
                cout<<"Queue Created!!!\n";
            }
            else
                cout<<"Queue already exists\n";
        }
        else if(ch==2){
            Ticket_Reservation n;
            cout<<"Enter a value to be enqueued: ";
            n.accept();
            enQ(n);
            cout<<"Value Enqueued\n";
        }
        else if(ch==3){
            node*t=f;
            while(t!=0){
                t->getData();
                cout<<endl;
                t=t->getNext();
            }
            cout<<endl;
        }
        else if(ch==4){
            Ticket_Reservation n;
            deQ(n);
            n.display();
            cout<<endl<<"The above ticket is dequeued"<<endl;
        }
        else if(ch==5){
            node* t=f;
            Ticket_Reservation n;
            while(t!=0){
                deQ(n);
                t=t->getNext();
            }
            cout<<"Queue Deleted!!\n";
        }
    }while(ch>0&&ch<6);
}
int main(){
    node n1;
    n1.menu();
}
