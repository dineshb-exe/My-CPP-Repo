#include<bits/stdc++.h>
using namespace std;

int main(){
    long int x;
    long int n;
    cin>>n;
    vector<int> prof;
    for(int i=0;i<n;i++){
        cin>>x;
        prof.push_back(x);
    }
    sort(prof.begin(),prof.end());
    int max1=0;
    for(int i=0;i<n;i++){
        long int v=(n-i)*prof[i];
        if(max1<v)
            max1=v;
    }
    cout<<max1;
}
