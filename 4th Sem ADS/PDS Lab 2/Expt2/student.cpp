#include<iostream>
#include<string.h>
using namespace std;

class student{
    char name[21];
    int rno;
    int age;
    int marks[6];
    char grade[3];
    public:
    void input(){
        cout<<"Enter the name: ";
        cin.getline(name,21);
        cout<<"Enter the register number: ";
        cin>>rno;
        cout<<"Enter the age of the student: ";
        cin>>age;
        int i=0;
        float avg=0.0;
        for(i=0;i<6;i++){
            cout<<"Enter the mark of subject "<<i+1<<": ";
            cin>>marks[i];
            avg+=marks[i];
        }
        avg/=6;
        if(avg>90.0){
            strcpy(grade,"O");
        }
        else if(avg>80.0){
            strcpy(grade,"A+");
        }
        else if(avg>70.0){
            strcpy(grade,"A");
        }
        else if(avg>60.0){
            strcpy(grade,"B+");
        }
        else if(avg>50.0){
            strcpy(grade,"B");
        }
        else
            strcpy(grade,"RA");
    }
    void display(){
        cout<<"Name: "<<name<<endl<<"Register Number: "<<rno<<endl<<"Age: "<<age<<endl<<"Marks: ";
        int i;
        for(i=0;i<6;i++){
            cout<<endl<<"Subject "<<i+1<<" : "<<marks[i]<<endl;
        }
        cout<<"Grade: "<<grade;
    }
};
int main(){
    student s1;
    s1.input();
    s1.display();
}
