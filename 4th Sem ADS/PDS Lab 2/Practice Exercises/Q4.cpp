#include<iostream>
#include<exception>
using namespace std;

class error{
	string what;
	public:
		error(string w=" "):what(w){
		}
		void display(){
			cout<<what;
		}
};
class stack_overflow:public error{
	string what;
	public:
		stack_overflow():error("Stack Overflow\n"){
		}
		void display(){
			cout<<what<<endl;
		}
};
class stack{
	int *a;
	int size;
	int top;
	int f;
	public:
		stack(){
			top=-1;
			f=0;
			size=0;
			a=0;
		}
		stack(int s){
			size=s;
			a=new int[size];
			f=1;
		}
		~stack(){
			delete[] a;
		}
		void create(){
			if(f==0){
				do{
					cout<<"Enter the size of the stack: ";
					cin>>size;
				}while(size>0);
				a=new int[size];
				cout<<"Enter the 1st element to be pushed into the stack: ";
				cin>>a[++top];
				f=1;
			}
			else{
				cout<<"Stack already exists!! \n";
			}
		}
		void push(int val){
			if(top==-1&&f==0){
				create();
			}
			else{
				try{
					if(top>size-1)
					throw stack_overflow();
					a[++top]=val;
				}
				catch(error so){
					so.display();
				}
			}
		}
		void pop(int& val){
			if(top==-1){
				cerr<<"Stack Underflow!!!\n";
			}
			else{
				val=a[top--];
				cout<<"Value popped!!\n";
			}
		}
		void delete_(){
			top=-1;
			f=0;
			delete[] a;
		}
};
int main(){
	stack s1(4);//Creates a stack of 4 elements
	int ch;
	do{
		cout<<"Enter 1 to create a stack!!\nEnter 2 to push an element\nEnter 3 to pop an element\nEnter 4 to delete the stack\nEnter 5 to quit\n";
		cin>>ch;
		switch(ch){
			case 1:{
				s1.create();
				break;
			}
			case 2:{
				int n;
				cout<<"Enter an element!!\n";
				cin>>n;
				s1.push(n);
				break;
			}
			case 3:{
				int n;
				s1.pop(n);
				cout<<n<<" popped out\n";
				break;
			}
			case 4:{
				s1.delete_();
				break;
			}
		}
	}while(ch>0&&ch<5);
	
}
