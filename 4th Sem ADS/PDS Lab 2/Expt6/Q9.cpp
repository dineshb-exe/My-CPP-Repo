#include<iostream>
#include<exception>
using namespace std;

class distance_{
    int feet;
    int inches;
public:
    distance_(){
        feet=0;
        inches=0;
    }
    distance_(int f,int i){
        feet=f;
        inches=i;
    }
    int getinches(){
        return inches;
    }

};

int main(){
    distance_ d1(12,131313);
    try{
        if(d1.getinches()>131313)
            throw std::overflow_error"Can't be more than 12 inches\n";
    }
    catch(std::overflow_error& e){
        cout<<e.what();
    }
}
