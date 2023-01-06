#include <iostream>
#include <limits.h>
#include <queue>
#include <string.h>
using namespace std;

bool bfs(vector<vector<int>> rGraph, int s, int t, int parent[]){

    vector<bool> visited;
    for(int i=0;i<6;i++)
        visited.push_back(0);

    queue<int> q;
    q.push(s);
    visited[s]=1;
    parent[s] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < 6; v++) {
            if (visited[v] == 0 && rGraph[u][v] > 0) {
                if (v == t) {
                    parent[v] = u;
                    return 1;
                }
                q.push(v);
                parent[v] = u;
                visited[v] = 1;
            }
        }
    }

    return 0;
}

int fordFulkerson(vector<vector<int>> graph, int s, int t){
    int u, v;
    vector<vector<int>> rGraph;
    for (u = 0; u < 6; u++){
        vector<int> x;
        for (v = 0; v < 6; v++){
            x.push_back(graph[u][v]);
        }
        rGraph.push_back(x);
    }
    int parent[6];

    int max_flow = 0;
    while (bfs(rGraph, s, t, parent)) {
        int path_flow = INT_MAX;
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }

        max_flow += path_flow;
    }
    return max_flow;
}

int main(){
    vector<vector<int>> g;
    g.push_back({ 0, 4, 3, 0, 0, 0 });
    g.push_back({ 0, 0, 0, 4, 0, 0 });
    g.push_back({ 0, 4, 0, 0, 6, 0 });
    g.push_back({ 0, 0, 3, 0, 0, 2 });
    g.push_back({ 0, 0, 0, 0, 0, 6 });
    g.push_back({ 0, 0, 0, 0, 0, 0 });

    cout<<"The maximum possible flow is "<<fordFulkerson(g, 0, 5);
    return 0;
}
