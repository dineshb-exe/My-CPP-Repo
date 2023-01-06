#include<iostream>
#include<vector>
#include<set>
#include<list>
#include<algorithm>
#include<limits>
using namespace std;

bool areAllVerticesMarked(vector<bool> b){
    bool ch=1;
    for(int i=0;i<6&&ch==1;i++){
        if(b[i]==0)
            ch=0;
    }
    return ch;
}

void prim(vector<vector<int>> a){
    vector<bool> marked;
    for(int i=0;i<6;i++)
        marked.push_back(0);
    int u=0;
    marked[0]=1;
    int sum=0;
    vector<vector<int>> op;
    for(int i=0;i<6;i++)
        op.push_back({0,0,0,0,0,0,0});

    while(!areAllVerticesMarked(marked)){
        int v=u+1;
        do{
            if(marked[v]==1){
                a[u][v]=INT_MAX;
            }
            int e=INT_MAX;
            int e3;
            auto e2=a[0].begin();
            for(int i=0;i<u;i++){
                auto m1=min_element(a[i].begin(),a[i].end());
                if(e>*m1){
                    e=*m1;
                    e2=find(a[i].begin(),a[i].end(),e);
                    e3=i;
                }
            }
            u=e3;
            if (e2 != a[0].end()){
                v=e2-a[0].begin();
            }
            else{
                v=-1;
            }
        }
        while(marked[v]==1);
        op[u][v]=1;
        a[u][v]=INT_MAX;
        u=v;
        marked[u]=1;

    }
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            cout<<op[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    vector<vector<int>> g1;
    g1.push_back({INT_MAX,28,INT_MAX,INT_MAX,INT_MAX,10,INT_MAX});
    g1.push_back({28,INT_MAX,16,INT_MAX,INT_MAX,INT_MAX,14});
    g1.push_back({INT_MAX,16,INT_MAX,12,INT_MAX,INT_MAX,INT_MAX});
    g1.push_back({INT_MAX,INT_MAX,12,INT_MAX,22,INT_MAX,18});
    g1.push_back({INT_MAX,INT_MAX,INT_MAX,22,INT_MAX,25,24});
    g1.push_back({10,INT_MAX,INT_MAX,INT_MAX,25,INT_MAX,INT_MAX});
    g1.push_back({INT_MAX,14,INT_MAX,18,24,INT_MAX,INT_MAX});
    prim(g1);
}
