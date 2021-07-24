#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
const int L = 20;

vector<vector<int>> adj, up;
vector<int> vis, tin, tout;
int n, t;

void dfs(int v=0, int p=0) {
  tin[v] = t++;
  up[v][0] = p;
  for(int i=1; i<L; i++)
    up[v][i] = up[up[v][i-1]][i-1];
  for(int u : adj[v])
    if(u!=p) dfs(u,v);
  tout[v] = t++;
}

bool is_ancestor(int u, int v) {
  return tin[u]<=tin[v] && tout[u]>=tout[v];
}

int lca(int u, int v) {
  if(is_ancestor(u,v)) return u;
  if(is_ancestor(v,u)) return v;
  for(int i=L-1; i>=0; i--)
    if(!is_ancestor(up[u][i],v))
      u = up[u][i];
  return up[u][0];
}

void init() {
  tin.resize(n);
  tout.resize(n);
  up.resize(n, vector<int>(L));
  t = 0;
  dfs();
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  int m, q, u, v;
  cin >> n >> m >> q;
  adj.resize(n);
  while(m--) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  init();
  while(q--) {
    cin >> u >> v;
    cout << lca(u, v) << '\n';
  }
  return 0;
}