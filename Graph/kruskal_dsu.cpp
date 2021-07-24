#include <bits/stdc++.h>
#define ll long long
using namespace std;

/*
Kruskal's algo for MST using DSU
input:
7 9
0 1 2
0 2 3
1 2 1
1 3 1
1 4 4
2 5 5
3 4 1
4 5 1
5 6 1

output:
7
6 5 1
5 4 1
1 2 1
1 3 1
4 3 1
1 0 2

*/

vector<int> parent, rankk;

void make_set(int v) {
  parent[v] = v;
  rankk[v] = 0;
}

int find_set(int v) {
  if (v == parent[v])
    return v;
  return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
  a = find_set(a);
  b = find_set(b);
  if (a != b) {
    if (rankk[a] < rankk[b])
      swap(a, b);
    parent[b] = a;
    if (rankk[a] == rankk[b])
      rankk[a]++;
  }
}

struct Edge {
  int u, v, weight;
  bool operator<(Edge const& other) {
    return weight < other.weight;
  }
};

int n, m;
vector<Edge> edges;

void Kruskal() {
  int cost = 0;
  vector<Edge> result;
  parent.resize(n);
  rankk.resize(n);
  for (int i = 0; i < n; i++)
    make_set(i);

  sort(edges.begin(), edges.end());

  for (Edge e : edges) {
    if (find_set(e.u) != find_set(e.v)) {
      cost += e.weight;
      result.push_back(e);
      union_sets(e.u, e.v);
    }
  }
  printf("%d\n", cost);
  for(auto e : result) {
    printf("%d %d %d\n", e.u, e.v, e.weight);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n >> m;
  edges.resize(m);
  for(int i=0; i<m; i++) {
    cin >> edges[i].u >> edges[i].v >> edges[i].weight;
  }
  Kruskal();
  return 0;
}