//1.	Write a program for Parameterized Constructor
#include<iostream>
#include<iomanip>
using namespace std;

class date{
    int d;
    int m;
    int y;
    public:
        date(){
            d=0;
            m=0;
            y=0;
        }
        date(int d1, int m1, int y1){
            d=d1;
            m=m1;
            y=y1;
        }
        void read(){
            cout<<"Enter the day of the month: ";
            cin>>d;
            cout<<"Enter the month: ";
            cin>>m;
            cout<<"Enter the year: ";
            cin>>y;
        }
        void display(){
            cout<<setw(2)<<setfill('0')<<d<<"/"<<setw(2)<<setfill('0')<<m<<"/"<<setw(4)<<setfill('0')<<y<<endl;
        }
};

class student{
    string name;
    int rno;
    date dob;
    int marks[6];
    float gp;
    public:
        student(){
            name="Unknown";
            int i;
            for(i=0;i<6;i++){
                marks[i]=-1;
            }
            gp=-1.0;
        }
        student(string n, int rn, date d1,int m[6]){
            int sum=0;
            name=n;
            rno=rn;
            dob=d1;
            int i;
            for(i=0;i<6;i++){
                marks[i]=m[i];
                sum+=m[i];
            }
            gp=sum/60.0;
        }
        void display1(){
            cout<<"Name: "<<name<<"\nRegister Number: "<<rno<<endl<<"Date of Birth: ";
            dob.display();
            int i;
            for(i=0;i<6;i++){
                cout<<"Mark of Subject No. "<<i+1<<marks[i]<<endl;
            }
            cout<<"Grade point of the student: "<<gp<<endl;
        }
};

int main(){
    string str;
    int rollno;
    cout<<"Enter the name of the student: ";
    cin>>str;
    cout<<"Enter the register number of the student: ";
    cin>>rollno;
    date d1(14,5,2001);
    int i,mrks[6];
    for(i=0;i<6;i++){
        cout<<"Enter the mark of subject "<<i+1<<": ";
        cin>>mrks[i];
    }
    student s1(str,rollno,d1,mrks);
    s1.display1();
}
