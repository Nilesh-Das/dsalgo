#include <bits/stdc++.h>
#define ll long long
using namespace std;

// Kahn's algo for topological sort
/*
input:
6 6
5 2
5 0
4 0
4 1
2 3
3 1
output:
4 5 2 0 3 1
*/

int n, m, u, v;
vector<vector<int>> adj;
vector<int> indegree;

void Kahn() {
  queue<int> q;
  for(int i=0; i<n; i++) {
    if(indegree[i]==0) q.push(i);
  }

  int idx = 0;
  vector<int> top_order(n);
  while(!q.empty()) {
    int u = q.front();
    q.pop();
    top_order[idx++] = u;
    for(int v : adj[u]) {
      indegree[v]--;
      if(indegree[v]==0) q.push(v);
    }
  }
  if(idx!=n) {
    cout << "Graph contains cycle\n";
  } else {
    for(int x : top_order)
      cout << x << ' ';
    cout << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  adj.resize(n);
  indegree.resize(n);
  for(int i=0; i<m; i++) {
    cin >> u >> v;
    adj[u].push_back(v);
    indegree[v]++;
  }
  Kahn();
  
  return 0;
}