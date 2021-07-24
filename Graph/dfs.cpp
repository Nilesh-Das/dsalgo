#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, m;
vector<vector<int>> adj;
vector<int> color;
vector<int> time_in, time_out;
int dfs_timer = 0;

// Depth First Search
void dfs(int u) {
  time_in[u] = dfs_timer++;
  color[u] = 1;
  for(int v : adj[u]) {
    if(color[v]) continue;
    dfs(v);
  }
  color[u] = 2;
  time_out[u] = dfs_timer++;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n >> m;
  adj.resize(n);
  color.resize(n);
  time_in.resize(n);
  time_out.resize(n);
  for(int i=0; i<m; i++) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(0);
  
  return 0;
}