#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9+7;

// Maxflow - Edmonds-Karp algorithm

int n;
vector<vector<int>> adj, cap;
vector<int> par;

int bfs(int s, int t) {
  int u, w, x;
  par.assign(n,-1);
  par[s]=-2;
  queue<pair<int, int>> q;
  q.push({s,INF});

  while(!q.empty()) {
    u = q.front().first;
    w = q.front().second;
    q.pop();
    for(int v : adj[u]) {
      if(par[v]==-1 && cap[u][v]) {
        par[v] = u;
        x = min(w, cap[u][v]);
        if(v==t) return x;
        q.push({v,x});   
      }
    } 
  }
}

int maxflow(int s, int t) {
  int w=0, x;
  while(x = bfs(s,t)) {
    w+=x;
    for(int u=t; u!=s; u=par[u]) {
      cap[par[u]][u] -= x;
      cap[u][par[u]] += x;
    }
  }
  return w;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  int m, s, t, u, v, w;
  cin >> n >> m >> s >> t;
  adj.resize(n);
  cap.resize(n, vector<int>(n));
  while(m--) {
    cin >> u >> v >> w;
    adj[u].push_back(v);
    adj[v].push_back(u);
    cap[u][v] = w;
    cap[v][u] = 0;
  }
  cout << maxflow(s, t) << '\n';
  return 0;
}