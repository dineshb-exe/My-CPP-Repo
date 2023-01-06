#include<iostream>
#include<fstream>

using namespace std;

int main(){
        int a;
        fstream f1("Numbers.dat",ios::binary|ios::out);
        do{
            cin>>a;
            f1.write((char*)&a,sizeof(int));
        }
        while(a>0);
        f1.close();
}
