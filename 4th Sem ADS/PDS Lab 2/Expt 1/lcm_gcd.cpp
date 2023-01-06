#include<iostream>
using namespace std;

class LCM_GCD{
    int a;
    int b;
    public:
        void input(){
            cout<<"Enter the 1st number: ";
            cin>>a;
            cout<<"Enter the 2nd number: ";
            cin>>b;
        }
        void compute_LCM(){
            int n1=a,n2=b;
            while(n1!=n2){
                if(n1<n2){
                    n1+=a;
                }
                else{
                    n2+=b;
                }
            }
            cout<<"The LCM of "<<a<<" and "<<b<<" is "<<n1;
        }
        void compute_GCD(){
            int i,gcd;
            for(i=1;i<=a&&i<=b;i++){
                if(a%i==0&&b%i==0)
                    gcd=i;
            }
            cout<<"The GCD of "<<a<<" and "<<b<<" is "<<gcd;
        }
};

int main(){
    LCM_GCD l1;
    l1.input();
    l1.compute_LCM();
    cout<<endl;
    l1.compute_GCD();
}
