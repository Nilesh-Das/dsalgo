#include <bits/stdc++.h>
#define ll long long
using namespace std;


// https://codeforces.com/contest/20/problem/C
const ll INF = 1e18;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> adj(n+1);
  for(int i=0; i<m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }
  // djikstra
  vector<ll> D(n+1, INF);
  vector<bool> Q(n+1, 0);
  vector<int> P(n+1, -1);
  D[1] = 0;

  set<array<ll, 2>> s;
  s.insert({D[1], 1});
  while(!s.empty()) {
    int u = (*s.begin())[1];
    s.erase(s.begin());
    if(Q[u]) continue;
    Q[u] = true;
    for(auto edge : adj[u]) {
      int v = edge.first;
      int l = edge.second;
      if(D[u] + l < D[v]) {
        D[v] = D[u] + l;
        P[v] = u;
        s.insert({D[v], v});
      }
    }
  }

  if(!Q[n]) {
    cout << -1 << '\n';
    return 0;
  }

  vector<int> path;
  for(int v=n; v!=1; v=P[v]) {
    path.push_back(v);
  }
  path.push_back(1);
  reverse(path.begin(), path.end());

  for(int x : path) {
    cout << x << ' ';
  }
  cout << '\n';
  
  return 0;
}