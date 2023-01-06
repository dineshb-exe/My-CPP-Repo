#include <iostream>
#include<string>
#include<vector>
using namespace std;

int Xcount(vector<string> a){
    int i=0,j=0;
    int xc=0;
    for(;i<3;i++){
        for(;j<3;j++)
        if(a[i][j]=='x')
        xc++;
    }
}
int Ocount(vector<string> a){
    int i=0,j=0;
    int oc=0;
    for(;i<3;i++){
        for(;j<3;j++)
        if(a[i][j]=='O')
        oc++;
    }
}
int winner(vector<string> a){
    int win=0;
    if((a[0]=="XXX"||a[1]=="XXX"||a[2]=="XXX")||(a[0][0]=='X'&&a[1][0]=='X'&&a[2][0]=='X')||(a[0][1]=='X'&&a[1][1]=='X'&&a[2][1]=='X')||(a[0][2]=='X'&&a[1][2]=='X'&&a[2][2]=='X')||(a[0][0]=='X'&&a[1][1]=='X'&&a[2][2]=='X')||(a[0][2]=='X'&&a[1][1]=='X'&&a[2][0]=='X'))
        win++;
    if((a[0]=="OOO"||a[1]=="OOO"||a[2]=="OOO")||(a[0][0]=='O'&&a[1][0]=='O'&&a[2][0]=='O')||(a[0][1]=='O'&&a[1][1]=='O'&&a[2][1]=='O')||(a[0][2]=='O'&&a[1][2]=='O'&&a[2][2]=='O')||(a[0][0]=='O'&&a[1][1]=='O'&&a[2][2]=='O')||(a[0][2]=='O'&&a[1][1]=='O'&&a[2][0]=='O'))
        win++;
    return win;
}
int main() {
	// your code goes here
	int T;
	cin>>T;
	string g;
	vector<string> ip;
	int i;
	for(i=0;i<T;i++){
	    for(int j=0;j<3;j++){
	        cin>>g;
	        ip.push_back(g);
	    }
	    int xc=Xcount(ip);
	    int oc=Ocount(ip);
	    int dc=9-xc-oc;
	    cout<<xc<<'\t'<<oc<<'\t';
	    if(xc-oc>1||winner(ip)==2){
	        cout<<"3"<<endl;
	    }
	    else if(xc-oc<=1&&winner(ip)==1){
	        cout<<"1"<<endl;
	    }
	    else if(xc-oc<=1&&winner(ip)==0&&dc>0){
	        cout<<"2"<<endl;
	    }
	    else if(xc-oc<=1&&winner(ip)==0&&dc==0){
	        cout<<"1"<<endl;
	    }
	}
	return 0;
}
/*
3
XOX
XXO
O_O
XXX
OOO
___
XOX
OX_
XO_
*/
