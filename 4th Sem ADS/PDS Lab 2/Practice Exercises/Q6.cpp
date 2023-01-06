#include<iostream>
using namespace std;

class fruit{
protected:
    static int c;
public:
	int getCount(){
		return c;
	}
};
class apple: public fruit{
    int quan;
public:
	apple(){
		cout<<"Apple is a fruit\n";
	}
    void add(int c1){
        quan=c1;
        c+=c1;
    }
};
class orange: public fruit{
    int quan;
public:
	orange(){
		cout<<"Orange is a fruit\n";
	}
    void add(int c2){
        quan=c2;
        c+=c2;
    }
};
int fruit::c=0;

int main(){
	apple a14;
	orange o2;
	int x1,x2;
	cout<<"Enter the count of apples: ";
	cin>>x1;
	cout<<"Enter the count of oranges: ";
	cin>>x2;
	a14.add(x1);
	o2.add(x2);
	cout<<"The count of both apples and oranges in the basket is: "<<a14.getCount();
}
