#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9+7;

// Maxflow - Edmonds-Karp algorithm

int n;
vector<vector<int>> adj, capacity;
vector<int> parent;

int bfs(int s, int t) {
  int curr, flow, new_flow;
  parent.assign(n, -1);
  parent[s] = -2;
  queue<pair<int, int>> q;
  q.push({s, INF});

  while(!q.empty()) {
    curr = q.front().first;
    flow = q.front().second;
    q.pop();
    for(int next : adj[curr]) {
      if(parent[next]==-1 && capacity[curr][next]) {
        parent[next] = curr;
        new_flow = min(flow, capacity[curr][next]);
        if(next==t) return new_flow;
        q.push({next, new_flow});
      }
    }
  }
}

int maxflow(int s, int t) {
  int flow=0, new_flow;
  while(new_flow=bfs(s,t)) {
    flow += new_flow;
    for(int curr=t; curr!=s; curr=parent[curr]) {
      capacity[parent[curr]][curr] -= new_flow;
      capacity[curr][parent[curr]] += new_flow;
    }
  }
  return flow;
}



int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  int m, s, t, u, v, w;
  cin >> n >> m >> s >> t;
  adj.resize(n);
  capacity.resize(n, vector<int>(n));
  while(m--) {
    cin >> u >> v >> w;
    adj[u].push_back(v);
    adj[v].push_back(u);
    capacity[u][v] = w;
    capacity[v][u] = 0;
  }
  cout << maxflow(s, t) << '\n';
  return 0;
}

/*
input:
6 9 0 5
0 1 7
0 2 4
1 3 5
1 4 3
2 1 3
2 4 2
3 5 8
4 3 3
4 5 5
output:
10
*/