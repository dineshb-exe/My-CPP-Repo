#include<iostream>
#include<conio.h>
#include<stdlib.h>
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
        cout<<"The date of journey: "<<doj.day<<'/'<<doj.month<<'/'<<doj.year<<endl;
    }
    void update(){
        int ch;
        do{
            cout<<"Enter 1 to update Ticket Number:\nEnter 2 to update city of departure\nEnter 3 to update city of arrival\nEnter 4 to update name of the passenger\nEnter 5 to update the date of journey\nEnter 6 to exit";
            cin>>ch;
            if(ch==1){
                cout<<"Enter the new Ticket Number: ";
                cin>>tid;
            }
            else if(ch==2){
                cout<<"Enter the new City of Departure: ";
                cin.getline(c_dep,21);
            }
            else if(ch==3){
                cout<<"Enter the new City of arrival: ";
                cin.getline(c_arr,21);
            }
            else if(ch==4){
                cout<<"Enter the new name of the passenger: ";
                cin.getline(passenger_name,21);
            }
            else if(ch==5){
                cout<<"Enter the new day of journey: ";
                cin>>doj.day;
                cout<<"Enter the new month of journey: ";
                cin>>doj.month;
                cout<<"Enter the new year of journey: ";
                cin>>doj.year;
            }
        }while(ch>0&&ch<6);
    }
};
int main(){
    int ch;
    Ticket_Reservation t1;
    do{
        cout<<"Enter 1 to accept details: \nEnter 2 to display the details\nEnter 3 to update details\nEnter 4 to quit: "<<endl;
        cin>>ch;
        system("cls");
        if(ch==1)
        t1.accept();
        else if(ch==2)
        t1.display();
        else if(ch==3)
        t1.update();
        getch();
        system("cls");
    }while(ch>0&&ch<4);
}
