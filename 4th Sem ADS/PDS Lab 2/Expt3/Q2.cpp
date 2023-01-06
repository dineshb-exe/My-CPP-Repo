#include<iostream>
using namespace std;

class user{
    static int purchase_count;
public:
    user(){
        purchase_count=0;
    }
    void Buy(){
        purchase_count++;
    }
    void Return(){
        if(purchase_count>0)
        purchase_count--;
        else
            cout<<"No product has been purchased!"<<endl;
    }
    void display(){
        cout<<"Number of products purchased so far: "<<purchase_count<<endl;
    }
    void menu(){
        int ch;
        do{
            cout<<"Enter 1 to buy an item\nEnter 2 to return an already purchased item\nEnter 3 to display the number of products purchased\nEnter 4 to exit\n";
            cin>>ch;
            if(ch==1){
                Buy();
                cout<<"Product Bought Successfully!!\n";
            }
            else if(ch==2){
                Return();
                cout<<"Product Returned Successfully!!\n";
            }
            else if(ch==3){
                display();
            }
        }while(ch>0&&ch<4);
    }
};
int user::purchase_count;
int main(){
    user u1;
    u1.menu();
}
