#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class graph{
    int nov;
    vector<vector<int>> a_list;
public:
    graph(int n=0):nov(n){
        for(int i=0;i<n;i++){
            a_list.push_back({});
        }
    }
    void add_vertex(){
        nov++;
        a_list.push_back({});
    }
    void add_edge(int v1, int v2,bool x=1){
        if(v1>=nov&&v2>=nov)
            return;
        if(x==1)
        a_list[v1].push_back(v2);
        else{
            a_list[v1].push_back(v2);
            a_list[v2].push_back(v1);
        }
    }
    void remove_edge(int v1,int v2, bool x=0){
        if(v1>=nov&&v2>nov)
            return;
        vector<int>::iterator i1;
        i1=find(a_list[v1].begin(),a_list[v1].end(),v2);
        if(i1==1){
            a_list[v1][v2]=0;
        }
    }

};
