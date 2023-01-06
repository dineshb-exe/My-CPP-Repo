#include<iostream>
#include<vector>
#include<set>
#include<list>
#include<algorithm>
using namespace std;

int main(){
    vector<vector<int>> g;
    vector<int> marked;
    int j;
    for(int i=0;i<6;i++){
        marked.push_back(0);
    }
    //100 is loaded as value for which distance is unknown
    g.push_back({0,4,2,100,100,100});
    g.push_back({4,0,1,5,100,100});
    g.push_back({2,1,0,8,10,100});
    g.push_back({100,5,8,0,2,6});
    g.push_back({100,100,100,6,5,0});
    set<int> s={0,4,2,100,100,100};
    set<int>::iterator itr=s.begin();
    itr++;
    int i=1;
    for(;i<5&&itr!=s.end();){
        auto e=find(g[0].begin(),g[0].end(),*itr);
        int index=1;
        if (e != g[0].end()){
            index=e-g[0].begin();
        }
        else {
            index=-1;
        }
        //Relaxation
        if(index>-1){
            for(int j=1;j<6;j++){
                if(g[0][index]+g[index][j]<g[0][j])
                    g[0][j]=g[0][index]+g[index][j];
            }
            set<int> v;
            for(int j=0;j<6;j++){
                v.insert(g[0][j]);
            }
            s=v;
            itr=s.begin();
            for(int k=0;k<i;k++)
                itr++;
        }
        i++;
    }
    cout<<"Distance from vertex A to other vetices: "<<endl;
    for(int j=0;j<6;j++){
        cout<<g[0][j]<<" ";
    }
}
