#include<iostream>

using namespace std;

class stack_{
    int* arr;
    int top;
    int n;
    int f=0;
    public:
        void Create(){
            cout<<"Enter the number of elements of the stack: ";
            cin>>n;
            arr=new int[n];
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
        void Push(int val){
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
        int Pop(){
            if(isEmpty()){
                cerr<<"STACK EMPTY!!"<<endl;
                return 0;
            }
            else{
                int v=arr[top--];
                return v;
            }
        }
        void display(){
            if(f==1){
                int i=top;
                while(i>=0){
                    cout<<arr[i]<<"->";
                    i--;
                }
            }
        }
};

int main(){
    stack_ s1;
    int ch,n;
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
            cout<<"Enter the value to be pushed: ";
            cin>>n;
            s1.Push(n);
        }
        else if(ch==3){
            cout<<s1.Pop()<<" Popped out of the stack!!\n";
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
