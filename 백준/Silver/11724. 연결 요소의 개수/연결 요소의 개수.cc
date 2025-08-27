#include<bits/stdc++.h>
using namespace std;

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

vector<int> vis;

void dfs(vector<vector<int>>& graph, int node_idx){

    if(vis[node_idx] == 1) return;

    vis[node_idx] = 1;

    if(graph[node_idx].size() > 0){

        for(int n_node_idx : graph[node_idx]){

            if(vis[n_node_idx] == 1) continue;

            dfs(graph, n_node_idx);

        }
    }


}

int main() {
    fastIO();
    
    int n, m;
    cin >> n >> m;


    vector<vector<int>> graph(n+1); // 1~n graph

    vis.assign(n+1, 0);


    for(int i=0; i<m; i++){

        int v1, v2;
        cin >> v1 >> v2;

        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }


    int cnt=0;
    for(int i=1; i<=n; i++){

        if(vis[i] == 0){

            dfs(graph, i);

            cnt++;
        }

    }


    cout << cnt << "\n";

    


    return 0;
}