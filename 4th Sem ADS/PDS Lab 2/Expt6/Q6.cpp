#include<iostream>
using namespace std;

template<class T>

class node{
    T data;
    node* next;
public:
    node(){
        data=0;
        next=0;
    }
    void Insert(T val, int pos);
    void Remove(T& val,int pos);
    void display();
    void del_list();
    void menu();
};

node<int> head;
void node::Insert(T val,int pos){
    if(head==0){
        head=new node;
        if(head){
            head->data=val;
            head->next=0;
        }
    }
    else{
        node* t=head;
        int i=0;
        while(t->next!=0&&i<pos){
            t=t->next;
            i++;
        }
        node* n1=new node;
        if(n1){
            n1->data=val;
            n1->next=0;
            t->next=n1;
        }
    }
}
void node<int>::Remove(int& val, int pos){
    if(head==0){
        cout<<"No elements in the list"<<endl;
    }
    else{
        node* t=head;
        int i=0;
        while(i<pos-1){
            t=t->next;
            i++;
        }
        val=(t->next)->data;
        node* n1=t->next;
        t->next=n1->next;
        delete n1;
    }
}
void node<int>::display(){
    node* t=head;
    while(t!=0){
        cout<<t->data"->";
        t=t->next;
    }
    cout<<endl;
}
void node<int>::del_list(){
    node* t=head;
    while(head!=0){
        t=head;
        head=head->next;
        delete t;
    }
}
void node<int>::menu(){
    int ch;
    do{
        cout<<"Enter 1 to create a list\nEnter 2 to enter an element\nEnter 3 to display elements\nEnter 4 to delete elements\nEnter 5 to delete list\nEnter 6 to quit: ";
        cin>>ch;
        if(ch==1){
            if(head==0){
                int n;
                cout<<"Enter a value to be inserted: ";
                cin>>n;
                Insert(n,0);
                cout<<"List Created!!!\n";
            }
            else
                cout<<"List already exists\n";
        }
        else if(ch==2){
            int n;
            int pos1;
            cout<<"Enter a value to be pushed: ";
            cin>>n;
            cout<<"Enter the position you want to store the value in: ";
            cin>>pos1;
            Insert(n,pos1);
            cout<<"Value Pushed\n";
        }
        else if(ch==3){
            node*t=head;
            while(t!=0){
                cout<<t->data<<"->";
                t=t->next;
            }
            cout<<endl;
        }
        else if(ch==4){
            int n;
            cout<<"Enter the position you want to store the value in: ";
            cin>>pos1;
            int pos1;

            Remove(n,pos1);
            cout<<n<<" Popped out"<<endl;
        }
        else if(ch==5){
            del_list();
            cout<<"Stack Deleted!!\n";
        }
    }while(ch>0&&ch<6);
}
int main(){
    node n1;
    n1.menu();
}
