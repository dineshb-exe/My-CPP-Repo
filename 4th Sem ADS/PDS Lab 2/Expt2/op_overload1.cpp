#include<iostream>
using namespace std;
class square{
    int side;
    public:
        square(){
            side=15;
			}
        void read(){
            cout<<"Enter the side of square: ";
            cin>>side;
        }
        square operator ++(){
            square res;
            ++res.side;
            return res;
        }
        void display(){
            cout<<"Length of the side of the sqaure: "<<side<<" units"<<endl;
            cout<<"*";
            int i,j;
            for(i=0;i<side;i++){
                cout<<" *";
            }
            cout<<" *";
            for(i=0;i<side;i++){
                if(i>=1){
                    cout<<"*";
                    for(j=0;j<side*2+1;j++){
                        cout<<" ";
                    }
                    cout<<"*";
                }
                cout<<"\n";
            }
            cout<<"*";
            for(i=0;i<side;i++){
                cout<<" *";
            }
            cout<<" *";
            cout<<endl;

        }
};

int main(){
    square s1;
    s1.display();
    square s2=++s1;
    s2.display();
}

