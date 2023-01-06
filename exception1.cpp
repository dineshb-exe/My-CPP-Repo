#include<iostream>
#include<exception>
using namespace std;

class distance{
    int feet;
    int inches;
public:
    distance(){
        feet=0;
        inches=0;
    }
    distance(int f,int i){
        feet=f;
        inches=i;
    }
    int getinches(){
        return inches;
    }

};
int main(){
    distance d;
    try{
        if(d.getinches()>12)
            throw overflow_error;
    }
    catch(std::overflow_error& e){
        cout<<e.what();
    }
}

