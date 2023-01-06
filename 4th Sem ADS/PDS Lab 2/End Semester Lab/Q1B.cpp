//Sri:


#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

const int N=7;

void BFS(vector<vector<int>> a,vector<string> c,int s){
    vector<bool> marked;
    queue<int> q;
    for(int i=0;i<s;i++)
        marked.push_back(0);
    marked[0]=1;
    cout<<c[0]<<"\t";
    q.push(0);
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        for(int i=0;i<s;i++){
            if(marked[i]==0&&a[cur][i]==1){
                q.push(i);
                marked[i]=1;
                cout<<c[i]<<"\t";
            }
        }
    }
}

int main(){
    vector<string> cities;
    vector<vector<int>> adj_cities;
    cities.push_back("Chennai");
    cities.push_back("Mumbai");
    cities.push_back("Hyderabad");
    cities.push_back("Delhi");
    cities.push_back("Bengaluru");
    cities.push_back("Kolkata");
    cities.push_back("Ahmedabad");
    adj_cities.push_back({0,1,1,1,0,0,0});
    adj_cities.push_back({1,0,1,1,0,0,0});
    adj_cities.push_back({0,0,0,0,1,1,0});
    adj_cities.push_back({0,0,0,0,1,1,0});
    adj_cities.push_back({0,0,0,0,0,1,1});
    adj_cities.push_back({0,0,0,0,1,0,1});
    adj_cities.push_back({0,0,0,0,0,0,0});
    cout<<"BFS Traversal of the graph:\n";
    BFS(adj_cities,cities,N);
}
