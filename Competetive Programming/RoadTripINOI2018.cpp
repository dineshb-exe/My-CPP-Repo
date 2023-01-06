#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<vector<int>> rt,prev;
    vector<int> museum;
    vector<int> museums2;
    vector<int> temp;
    vector<bool> marked;
    vector<bool> temp2;
    int t,a,b,z;
    long int n,m,k;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n>>m>>k;

        temp.assign(n,0);
        temp2.assign(n,0);
        rt.assign(n,temp);
        marked.assign(n,temp2);
        museums2.assign(n,0);
        for(int it=0;it<n;it++)
            rt[it][it]=1;
        for(int j=0;j<m;j++){
            cin>>a>>b;
            rt[a-1][b-1]=1;
            rt[b-1][a-1]=1;
        }
        for(int h=0;h<n;h++){
            cin>>z;
            museum.push_back(z);
        }
        prev=rt;
        /*
        for(int k3=0;k3<n;k3++){
            for(int j3=0;j3<n;j3++){
                if(rt[i3][j3]==0&&prev[i3][k3]==1&&prev[k3][j3]==1){
                    rt[i3][j3]=1;
                }
                if(rt[i3][j3]==1&&marked[i3][j3]==0){
                    museums2[i3]=museums2[i3]+museum[j3];
                    marked[i3][j3]=1;
                }
            }
            prev=rt;
        }
        */
        queue<int> q;
        vector<int> mark;
        for(int i=0;i<6;i++)
        mark.push_back(0);
        mark[0]=1;
        q.push(0);
        int curr;
        while(!q.empty()){
            curr=q.front();
            q.pop();
            cout<<b[curr]<<"\t";
            for(int i=0;i<6;i++){
                if(a[curr][i]==1&&mark[i]==0){
                    mark[i]=1;
                    q.push(i);
                }
            }
        }
    }
}
