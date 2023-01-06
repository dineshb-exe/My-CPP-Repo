#include<bits/stdc++.h>
using namespace std;

int parent[10];

int find_(int i){
    if(parent[i]==i)
        return i;
    else{
        return find_(parent[i]);
    }
}
void union_(int i,int j){
    int irep=find_(i);
    int jrep=find_(j);
    parent[irep]=jrep;
}

int main(){
    int a,b;
    for(int i=0;i<10;i++){
        parent[i]=i;
    }
    vector<pair<int,int>> x;
    cout<<"Enter the pairs: ";
    do{
        cin>>a>>b;
        if(a>=0&&b>=0){
            x.push_back(make_pair(a-1,b-1));
        }
    }
    while(a>=0&&b>=0);
    auto it=x.begin();
    while(it!=x.end()){
        union_(it->first,it->second);
        it++;
    }
    for(int i=0;i<10;i++){
        cout<<parent[i]<<endl;
    }
}
