#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

vector<int> mark2;

void BFS(vector<vector<int>> a,vector<string> b){
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
void DFS(vector<vector<int>> a,vector<string> b,int v){
    if(mark2[v]==0){
        mark2[v]=1;
        cout<<b[v]<<" ";
        for(int i=0;i<6;i++){
            if(a[v][i]==1&&mark2[i]==0)
                DFS(a,b,i);
        }
    }
}
int main(){
    int n=6;
    vector<string> cities={"Chennai","Mumbai","Ahmedabad","Delhi","Bangalore","Kolkata"};
    vector<vector<int>> citygraph;
    citygraph.push_back({0,1,1,1,0,0});
    citygraph.push_back({1,0,1,1,0,0});
    citygraph.push_back({0,0,0,0,1,1});
    citygraph.push_back({0,0,0,0,1,1});
    citygraph.push_back({0,0,1,0,0,1});
    citygraph.push_back({0,0,1,0,1,0});
    BFS(citygraph,cities);
    for(int i=0;i<6;i++)
        mark2.push_back(0);
    cout<<"\n";
    DFS(citygraph,cities,0);
}
