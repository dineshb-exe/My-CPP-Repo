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
class queue_{
    Inventory* arr;
    int f;
    int r;
    int n;
    int fl=0;
    public:
        void Create(){
            cout<<"Enter the number of elements of the queue: ";
            cin>>n;
            arr=new Inventory[n];
            f=-1;
            r=-1;
            fl=1;
        }
        void Delete_Q(){
            delete []arr;
            fl=0;
            f=-1;
            r=-1;
        }
        int isFull(){
            return ((r==n-1)&&(f==0))||(r==f-1);
        }
        int isEmpty(){
            return (f==-1);
        }
        void enQ(Inventory val){
            if(isFull()){
                cerr<<"Queue FULL!!!"<<endl;
            }
            else{
                if(fl==0){
                    Create();
                }
                if(f==-1){
                    f=r=0;
                    arr[r]=val;
                }
                else if(r==n-1){
                    r=0;
                    arr[r]=val;
                }
                else{
                    r++;
                    arr[r]=val;
                }
            }
        }
        Inventory deQ(){
            Inventory v;
            if(isEmpty()){
                cerr<<"Queue EMPTY!!"<<endl;
            }
            else if(f==r){
                v=arr[f];
                f=r=-1;
            }
            else if(f==n-1){
                v=arr[f];
                f=0;
            }
            else{
                v=arr[f];
                f++;
            }
            return v;
        }

        void display(){
            if(fl==1&&f>-1&&r>-1){
                int i=f;
                do{
                    arr[i].display();
                    cout<<endl;
                    i=(i+1)%n;
                    cin.get();
                }while(i<=r&&i!=f);
            }
        }
};

int main(){
    queue_ q1;
    int ch;
    Inventory n;
    do{
        cout<<endl;
        q1.display();
        cout<<"\nEnter 1 to Create a queue\nEnter 2 to enqueue an element\nEnter 3 to dequeue an element\nEnter 4 to check if the queue is empty\nEnter 5 to check if the queue is full\nEnter 6 to delete the queue\nEnter 7 to exit: \n";
        cin>>ch;
        if(ch==1){
            q1.Create();
            cout<<"Queue Created!!\n";
        }
        else if(ch==2){
            n.accept();
            q1.enQ(n);
            cout<<"\nProduct Enqueued "<<endl;
        }
        else if(ch==3){
            q1.deQ().display();
            cout<<"Product dequeued from the queue!!\n";
        }
        else if(ch==4){
            if(q1.isEmpty()==0){
                cout<<"Queue is not empty!!";
            }
            else{
                cout<<"Queue is Empty";
            }
        }
        else if(ch==5){
            if(q1.isFull()==0){
                cout<<"Queue is not full!!";
            }
            else{
                cout<<"Queue is Full";
            }
        }
        else if(ch==6){
            q1.Delete_Q();
            cout<<"Queue Deleted!!\n";
        }
    }while(ch>0&ch<7);
}
