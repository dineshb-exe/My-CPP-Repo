#include<iostream>
using namespace std;
const int N=2;
template <class type>
class matrix{
    type** a;//2D Array
    int row;
    int column;
public:
    matrix(){
        a=0;
        row=3;
        column=3;
    }
    void accept(){
        for(int i=0;i<row;i++){
            for(int j=0;j<column;j++){
                cout<<"Enter the value: ";
                cin>>a[i][j];
            }
        }
    }
    void display(){
        for(int i=0;i<row;i++){
            for(int j=0;j<column;j++){
                cout<<a[i][j]<<"\t";
            }
            cout<<endl;
        }
    }
};

int main(){
    matrix<int> a;
    matrix<float> b;
    a.accept();
    a.display();
    b.accept();
    b.display();

}

