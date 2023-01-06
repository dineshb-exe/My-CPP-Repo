//Sri:


#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
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
    void accept(){
        cout<<"Enter the day: ";
        cin>>d;
        cout<<"Enter the month: ";
        cin>>m;
        cout<<"Enter the year: ";
        cin>>y;
    }
    void display(){
        cout<<endl<<setw(2)<<setfill('0')<<d<<"/"<<setw(2)<<setfill('0')<<m<<"/"<<setw(4)<<setfill('0')<<y<<endl;
    }
};

class student{
    string name;
    int reg_no;
    char gender;
    date dob;
    vector<int> marks;
    string grade;
    int subjects;
    float average;
public:
    student(){
        name="Unknown";//Undefined
        reg_no=0;//Undefined
        gender='U';//Undefined
        grade="NA";
        subjects=0;
        average=0.0;
    }
    void accept(){
        cout<<"Enter the name of the student: ";
        cin>>name;
        cout<<"Enter the register number of the student: ";
        cin>>reg_no;
        cout<<"Enter the gender of the student: ";
        cin>>gender;
        cout<<"Enter the number of subjects of the student: ";
        cin>>subjects;
        cout<<"Enter the Date of birth of the student: "<<endl;
        dob.accept();
        int val;
        for(int i=0;i<subjects;i++){
            cout<<"Enter the mark: ";
            cin>>val;
            average+=val;
            marks.push_back(val);
        }
        average/=subjects;
        if(average>90.0&&average<=100.0)
            grade="O";
        else if(average<=90.0&&average>80.0)
            grade="A+";
        else if(average<=80.0&&average>70.0)
            grade="A";
        else if(average<=70.0&&average>60.0)
            grade="B+";
        else if(average<=60.0&&average>50.0)
            grade="B";
        else
            grade="C";
    }
    void display(){
        cout<<"Name: "<<name<<endl;
        cout<<"Register Number: "<<reg_no<<endl;
        cout<<"Gender: "<<gender<<endl;
        cout<<"Number of subjects: "<<subjects<<endl;
        cout<<"Date of Birth: "<<endl;
        dob.display();
        vector<int>::iterator i;
        cout<<"Marks in respective subjects: "<<endl;
        for(i=marks.begin();i!=marks.end();i++){
            cout<<*i<<endl;
        }
        cout<<"Average Marks: "<<average<<endl;
        cout<<"Grade: "<<grade<<endl;
    }
};

int main(){
    student s1;
    student* sp=&s1;
    sp->accept();
    sp->display();
}
