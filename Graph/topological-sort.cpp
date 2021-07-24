#include <bits/stdc++.h>
#define ll long long
using namespace std;

// DFS based approach
// https://en.wikipedia.org/wiki/Topological_sorting#Depth-first_search


vector<vector<int>> adj;
vector<int> vis;
vector<int> top_order;

void dfs(int u) {
    if(vis[u] == 2) return;
    if(vis[u] == 1) {
        cout << "stop" << '\n';
        exit(0);
    }

    vis[u] = 1;

    for(int v : adj[u]) dfs(v);

        vis[u] = 2;

    top_order.push_back(u);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;

    adj.resize(n);
    vis.resize(n);

    int u, v;

    for(int i=0; i<m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
    }

    // top sort
    for(int u=0; u<n; u++) {
        if(vis[u] == 0) dfs(u);
    }

    reverse(top_order.begin(), top_order.end());

    for(int x : top_order) {
        cout << x << ' ';
    }
    cout << '\n';
    
    return 0;
}