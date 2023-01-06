//Write a program for Constructor Overloading.
#include<iostream>
using namespace std;
class Cuboid{
    int length;
    int breadth;
    int height;
    int tsa;//Total Surface Area
    int lsa;//Lateral Surface Area
    int volume;// Volume of the solid
public:
    Cuboid(){
        length=breadth=height=lsa=tsa=volume=0;
    }
    Cuboid(int l,int b, int h){
        length=l;
        breadth=b;
        height=h;
        CalcLSA();
        CalcTSA();
        CalcVol();
    }
    void accept(){
        cout<<"Enter the length of the cuboid";
        cin>>length;
        cout<<"Enter the breadth of the cuboid";
        cin>>breadth;
        cout<<"Enter the height of the cuboid";
        cin>>height;
    }
    void CalcLSA(){
        lsa=2*height*(length+breadth);
    }
    void CalcTSA(){
        tsa=2*((length*breadth)+(length*height)+(height*breadth));
    }
    void CalcVol(){
        volume=length*breadth*height;
    }
    void display(){
        cout<<"Length of the cuboid: "<<length<<"\nBreadth of the cuboid: "<<breadth<<"\nHeight of the cuboid: "<<height<<"\nLateral Surface Area: "<<lsa<<"\nTotal Surface Area: "<<tsa<<"\nVolume: "<<volume<<endl;
    }
};
int main(){
    Cuboid c1,c2(5,2,7);
    c1.display();
    c2.display();
}
