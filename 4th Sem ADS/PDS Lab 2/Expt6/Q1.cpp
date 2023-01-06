#include<iostream>
using namespace std;

class student{
    string name;
    int rno;
    char sex;
    string blood_grp;
    int* marks;
    int n_sub=5;
public:
    student(){
        name="Unknown";
        rno=0;
        sex='0';
        blood_grp="UD";
        cout<<"Enter the number of subjects: ";
        cin>>n_sub;
        marks=new int[n_sub];
    }
    ~student(){
        delete[] marks;
    }

    void accept(){
        cout<<"Enter the name of the student: ";
        cin>>name;
        cin.get();
        cout<<"Enter the register number: ";
        cin>>rno;
        cin.get();
        cout<<"Enter the sex of the student: ";
        cin>>sex;
        cout<<"Enter the blood group of the student: ";
        cin>>blood_grp;
        cin.get();
        int i;
        for(i=0;i<n_sub;i++){
            cout<<"Enter the mark of subject "<<i+1<<": ";
            cin>>marks[i];
        }
    }
    void display(){
        cout<<"Name: "<<name<<endl;
        cout<<"Register number: "<<rno<<endl;
        cout<<"Sex: "<<sex<<endl;
        cout<<"Blood Group: "<<blood_grp<<endl;
        int i;
        for(i=0;i<n_sub;i++){
            cout<<"Mark of subject "<<i+1<<": ";
            cout<<marks[i]<<endl;
        }
    }
};
int main(){
    student s1;
    student* s=&s1;
    s->accept();
    s->display();
}
