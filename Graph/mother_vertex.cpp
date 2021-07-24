// Program to find a mother vertex in O(V+E) time in graph
#include <bits/stdc++.h>
#define ll long long
using namespace std;
/*
input:
5 5
1 0
0 2
2 1
0 3
3 4

output:
MotherVertex is 0
*/


vector<vector<int>> adj;
vector<int> vis;
int n, m, u, v;

void dfs(int u) {
    vis[u] = true;
    for(int v : adj[u])
        if(!vis[v]) dfs(v);
}

void FindMotherVertex() {
    vis.resize(n);
    int v = 0;
    for(int i=0; i<n; i++)
        if(!vis[i]) dfs(i), v=i;
    vis.resize(n, 0);
    dfs(v);
    for(int i=0; i<n; i++) {
        if(!vis[i]) {
            cout << "No MotherVertex\n";
            return;
        }
    }
    cout << "MotherVertex is " << v << '\n'; 
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    adj.resize(n);
    for(int i=0; i<n; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
    }

    FindMotherVertex();
    
    return 0;
}