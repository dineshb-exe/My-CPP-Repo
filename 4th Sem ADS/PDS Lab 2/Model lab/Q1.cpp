#include<iostream>
#include<stdlib.h>
using namespace std;
class shape{
    int f;
public:
    shape(){
        f=0;
    }
    void draw(){
        cout<<"The shape is not defined, so can't be drawn\n";
        f=1;
    }
    void erase_(){
        if(f){
            system("cls");
            cout<<"Shape erased!!!\n";
        }
        else
            cout<<"Shape not drawn, so can't be erased!\n";
        f=0;
    }
};
class circle:public shape{
    int f;
public:
    circle(){
        f=0;
    }
    void draw(){
        cout<<"Circle Drawn!\n";
        f=1;
    }
    void erase_(){
        if(f){
            system("cls");
            cout<<"Circle erased!!!\n";
        }
        else
            cout<<"Circle not drawn, so can't be erased!\n";
        f=0;
    }
};
class triangle:public shape{
    int f;
public:
    triangle(){
        f=0;
    }
    void draw(){
        cout<<"Triangle Drawn!\n";
        f=1;
    }
    void erase_(){
        if(f){
            system("cls");
            cout<<"Triangle erased!!!\n";
        }
        else
            cout<<"Triangle not drawn, so can't be erased!\n";
        f=0;
    }
};
class square: public shape{
    int f;
public:
    sqaure(){
        f=0;
    }
    void draw(){
        cout<<"Square drawn\n";
        f=1;
    }
    void erase_(){
        if(f){
            system("cls");
            cout<<"Square erased!!!\n";
        }
        else
            cout<<"Square not drawn, so can't be erased!\n";
        f=0;
    }
};
main(){
    int ch;
    shape s1;
    square sq1;
    triangle t1;
    circle c1;
    do{
        cout<<"1. Draw a shape\n2. Erase the shape\n3. Draw a sqaure\n4. Erase the square\n5. Draw a triangle\n6. Erase the triangle\n7. Draw the circle\n8. Erase the circle\n9. Quit\nEnter your choice: ";
        cin>>ch;
        if(ch==1)
            s1.draw();
        else if(ch==2)
            s1.erase_();
        else if(ch==3)
            sq1.draw();
        else if(ch==4)
            sq1.erase_();
        else if(ch==5)
            t1.draw();
        else if(ch==6)
            t1.erase_();
        else if(ch==7)
            c1.draw();
        else if(ch==8)
            c1.erase_();
    }while(ch>0&&ch<9);

}
