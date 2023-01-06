#include<iostream>
using namespace std;

class Father{
public:
    Father(){
        cout<<"A man has become a father "<<endl;
    }
};
class Mother{
public:
    Mother(){
        cout<<"A woman has become a mother "<<endl;
    }
};
class Child: public Father, Mother{
public:
    Child(){
        cout<<"A Child is born by inheriting the characteristics of his/her parents!! "<<endl;
    }
};
int main(){
    Child c1;
}
