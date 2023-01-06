#include<iostream>
using namespace std;
class node{
    int data;
    node* next;
public:
    node(){
        data=0;
        next=0;
    }
    void setData(int x){
        data=x;
    }
    int getData(){
        return data;
    }
    node* getNext(){
        return next;
    }
    void push(int v);
    void pop(int& v);
    void menu();
};

node*top=0;
void node::push(int v){
        node* tmp=new node;
        tmp->data=v;
        tmp->next=top;
        top=tmp;
    }
void node::pop(int &v){
    if(top){
        node*tmp=top;
        v=tmp->data;
        top=top->next;
        delete tmp;
    }
    else
        cerr<<"Stack Empty!! "<<endl;
}
void node::menu(){
    int ch;
    do{
        cout<<"Enter 1 to create a stack\nEnter 2 to push an element\nEnter 3 to display elements\nEnter 4 to pop elements\nEnter 5 to delete stack\nEnter 6 to quit: ";
        cin>>ch;
        if(ch==1){
            if(top==0){
                int n;
                cout<<"Enter a value to be pushed: ";
                cin>>n;
                push(n);
                cout<<"Stack Created!!!\n";
            }
            else
                cout<<"Stack already exists\n";
        }
        else if(ch==2){
            int n;
            cout<<"Enter a value to be pushed: ";
            cin>>n;
            push(n);
            cout<<"Value Pushed\n";
        }
        else if(ch==3){
            node*t=top;
            while(t!=0){
                cout<<t->getData()<<"->";
                t=t->getNext();
            }
            cout<<endl;
        }
        else if(ch==4){
            int n;
            pop(n);
            cout<<n<<" Popped out"<<endl;
        }
        else if(ch==5){
            node* t=top;
            int n;
            while(t!=0){
                pop(n);
                t=t->getNext();
            }
            cout<<"Stack Deleted!!\n";
        }
    }while(ch>0&&ch<6);
}
int main(){
    node n1;
    n1.menu();
}
