//Sri:
#include<iostream>
#include<vector>
#include<set>
#include<list>
#include<algorithm>
using namespace std;

int main(){
    vector<vector<int>> g;
    g.push_back({0,5,1,2});
    g.push_back({5,0,3,100});
    g.push_back({1,3,0,4});
    g.push_back({2,100,4,0});
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            for(int k=0;k<4;k++){
                if(g[i][j]>g[i][k]+g[k][j])
                    g[i][j]=g[i][k]+g[k][j];
            }
        }
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cout<<g[i][j]<<" ";
        }
        cout<<endl;
    }
}
