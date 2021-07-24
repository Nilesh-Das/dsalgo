#include <iostream>
#include <vector>
using namespace std;

// Finding Bridges in O(n + m)

const int N = 1e5+5;
vector<int> adj[N];
int n;

vector<bool> vis;
vector<int> tin, low;
int timer;
vector<vector<int>> bridges;

void dfs(int u, int p=-1) {
    vis[u] = true;
    tin[u] = low[u] = timer++;
    for(int v : adj[u]) {
        if(v == p) continue;
        if(vis[v]) {
            low[u] = min(low[u], tin[v]);
            continue;
        }
        dfs(v, u);
        low[u] = min(low[u], low[v]);
        if(low[v] > tin[u])
            bridges.push_back({u, v});
    }
}

void find_bridges() {
    timer = 0;
    vis.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for(int i = 0; i < n; i++)
        if(!vis[i]) dfs(i);
}

int main() {
    cin >> n;
    int u, v;
    for(int i = 0; i < n; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    find_bridges();
    for(int i = 0; i < bridges.size(); i++) {
        for(int j = 0; j < bridges[i].size(); j++) {
            cout << bridges[i][j] << ' ';
        }
        cout << '\n';
    }
}

