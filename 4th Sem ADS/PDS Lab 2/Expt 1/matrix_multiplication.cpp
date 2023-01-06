#include<iostream>

const int N=10;

using namespace std;

class Matrix_Multiplication{
    int r1;
    int c1;
    int r2;
    int c2;
    int r3;
    int c3;
    int a[N][N];
    int b[N][N];
    int c[N][N];
    public:
        Matrix_Multiplication(){
            r1=0;
            c1=0;
            r2=0;
            c2=0;
            r3=0;
            c3=0;
        }
        int ipMatrices(){
            cout<<"Enter the number of rows of matrix 1 (Limit: "<<N<<")";
            cin>>r1;
            cout<<"Enter the number of columns of matrix 1 (Limit: "<<N<<")";
            cin>>c1;
            cout<<"Enter the number of rows of matrix 2 (Limit: "<<N<<")";
            cin>>r2;
            cout<<"Enter the number of columns of matrix 2 (Limit: "<<N<<")";
            cin>>c2;
            if(c1!=r2){
                cerr<<"Invalid Input!!\n Please Enter again \n";
                return 0;
            }
            else{
                int i,j;
                for(i=0;i<r1;i++){
                    for(j=0;j<c1;j++){
                        cout<<"Enter the element: ";
                        cin>>a[i][j];
                    }
                }
                for(i=0;i<r2;i++){
                    for(j=0;j<c2;j++){
                        cout<<"Enter the element: ";
                        cin>>b[i][j];
                    }
                }
                return 1;
            }
        }
        void Multiply(){
            while(ipMatrices()==0);
            int i,j,k;
            r3=r1;
            c3=c2;
            for(i=0;i<r3;i++){
                for(j=0;j<c3;j++){
                    c[i][j]=0;
                }
            }
            for(i=0;i<r1;i++){
                for(j=0;j<c2;j++){
                    for(k=0;k<r2;k++){
                        c[i][j]+=(a[i][k]*b[k][j]);
                    }
                }
            }
        }
        void display(){
            int i,j;
            cout<<"Matrix A: \n";
            for(i=0;i<r1;i++){
                for(j=0;j<c1;j++){
                    cout<<a[i][j]<<"\t";
                }
                cout<<endl;
            }
            cout<<"Matrix B: \n";
            for(i=0;i<r2;i++){
                for(j=0;j<c2;j++){
                    cout<<b[i][j]<<"\t";
                }
                cout<<endl;
            }
            cout<<"The resultant matrix after multiplication of the ablove matrices is: \n";
            for(i=0;i<r3;i++){
                for(j=0;j<c3;j++){
                    cout<<c[i][j]<<"\t";
                }
                cout<<endl;
            }
        }
};

int main(){
    Matrix_Multiplication m1;
    m1.Multiply();
    m1.display();
}
