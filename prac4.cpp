#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;

class ITEM{
    int item_no;
    char description[100];
    int quantity;
    float rate;
    public:
        void setno(int n){
            item_no=n;
        }
        void setDesc(char d[100]){
            strcpy(description,d);
        }
        void setQuan(int q){
            quantity=q;
        }
        void setrate(float r){
            rate=r;
        }
        int getno(){
            return item_no;
        }
        char* getDesc(){
            return description;
        }
        int getQuan(){
            return quantity;
        }
        float getrate(){
            return rate;
        }
        ITEM(){
            item_no=0;
            quantity=0;
            rate=0.0;
            description[0]='\0';
        }
        ~ITEM(){
            description[0]='\0';
        }
};
int main(){

}
