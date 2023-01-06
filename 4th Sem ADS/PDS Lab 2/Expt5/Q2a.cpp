#include<iostream>
#include<string>
#include<string.h>
#include<iomanip>
using namespace std;

struct date{
    int day;
    int month;
    int year;
};

class Inventory{
    string name;
    int pid;
    date mfg_d;
    int quan;
    date exp_d;
public:
    Inventory(){
        name="Unknown";
        pid=-1;
        mfg_d.day=0;
        mfg_d.month=0;
        mfg_d.year=0;
        exp_d.day=0;
        exp_d.month=0;
        exp_d.year=0;
        quan=0;
    }
    void accept(){
        cout<<"Enter the product ID of the product: ";
        cin>>pid;
        cout<<"Enter the name of the product: ";
        cin>>name;
        cin.get();
        cout<<"Enter the manufactured day: ";
        cin>>mfg_d.day;
        cout<<"Enter the manufactured month: ";
        cin>>mfg_d.month;
        cout<<"Enter the manufactured year: ";
        cin>>mfg_d.year;
        cout<<"Enter the expiry day: ";
        cin>>exp_d.day;
        cout<<"Enter the expiry month: ";
        cin>>exp_d.month;
        cout<<"Enter the expiry year: ";
        cin>>exp_d.year;
        cout<<"Enter the quantity: ";
        cin>>quan;
    }
    void display(){
        cout<<"Product ID: "<<pid<<endl;
        cout<<"Product: "<<name<<endl;
        cout<<"Manufactured Date: "<<setw(2)<<setfill('0')<<mfg_d.day<<"/"<<setw(2)<<setfill('0')<<mfg_d.month<<"/"<<setw(4)<<setfill('0')<<mfg_d.year<<endl;
        cout<<"Expiry Date: "<<setw(2)<<setfill('0')<<exp_d.day<<"/"<<setw(2)<<setfill('0')<<exp_d.month<<"/"<<setw(4)<<setfill('0')<<exp_d.year<<endl;
        cout<<"Quantity in the inventory: "<<quan<<endl;
    }
};
class stack_{
    Inventory* arr;
    int top;
    int n;
    int f=0;
    public:
        void Create(){
            cout<<"Enter the number of elements of the stack: ";
            cin>>n;
            arr=new Inventory[n];
            top=-1;
            f=1;
        }
        void Delete_Stack(){
            delete []arr;
            f=0;
            top=-1;
        }
        int isFull(){
            return (top==n-1);
        }
        int isEmpty(){
            return (top==-1);
        }
        void Push(Inventory val){
            if(isFull()){
                cerr<<"STACK FULL!!!"<<endl;
            }
            else{
                if(f==0){
                    Create();
                }
                arr[++top]=val;
            }
        }
        Inventory Pop(){
            Inventory v;
            if(isEmpty()){
                cerr<<"STACK EMPTY!!"<<endl;
            }
            else{
                v=arr[top--];
            }
            return v;
        }
        void display(){
            if(f==1){
                int i=top;
                while(i>=0){
                    arr[i].display();
                    cout<<endl;
                    i--;
                }
            }
        }
};

int main(){
    stack_ s1;
    int ch;
    Inventory n;
    do{
        cout<<endl;
        s1.display();
        cout<<"\nEnter 1 to Create a stack\nEnter 2 to push an element\nEnter 3 to pop an element\nEnter 4 to check if the stack is empty\nEnter 5 to check if the stack is full\nEnter 6 to delete the stack\nEnter 7 to exit: \n";
        cin>>ch;
        if(ch==1){
            s1.Create();
            cout<<"Stack Created!!\n";
        }
        else if(ch==2){
            n.accept();
            s1.Push(n);
        }
        else if(ch==3){
            s1.Pop().display();
            cout<<"Product Popped out of the stack!!\n";
        }
        else if(ch==4){
            if(s1.isEmpty()==0){
                cout<<"Stack is not empty!!";
            }
            else{
                cout<<"Stack is Empty";
            }
        }
        else if(ch==5){
            if(s1.isFull()==0){
                cout<<"Stack is not full!!";
            }
            else{
                cout<<"Stack is Full";
            }
        }
        else if(ch==6){
            s1.Delete_Stack();
            cout<<"Stack Deleted!!\n";
        }
    }while(ch>0&ch<7);
}
