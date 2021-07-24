#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define vvi vector<vector<int>>
#define ump unordered_map

const int N = 1e5;

// LCA algorithm with DSU

int n;
vector<vector<int>> adj;
vector<vector<int>> queries;
vector<int> ancestor;
vector<bool> visited;
int parent[N];
int rnk[N];

void make_set(int v) {
    parent[v] = v;
    rnk[v] = 0;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if(a != b) {
        if(rnk[a] < rnk[b])
            swap(a, b);
        parent[b] = a;
        if(rnk[a]==rnk[b])
            rnk[a]++;
    }
}

void dfs(int v) {
    visited[v] = true;
    ancestor[v] = v;
    for (int u : adj[v]) {
        if (!visited[u]) {
            dfs(u);
            union_sets(v, u);
            ancestor[find_set(v)] = v;
        }
    }
    for (int other_node : queries[v]) {
        if (visited[other_node])
            cout << "LCA of " << v << " and " << other_node
        << " is " << ancestor[find_set(other_node)] << ".\n";
    }
}

void compute_LCAs() {
  // initialize n, adj and DSU
  // for (each query (u, v)) {
  //    queries[u].push_back(v);
  //    queries[v].push_back(u);
  // }
    for(int i=0; i<n; i++) make_set(i);
        ancestor.resize(n);
    visited.assign(n, false);
    dfs(0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int m, u, v, q;
    cin >> n >> m >> q;
    adj.resize(n);
    for(int i=0; i<n; i++)
        make_set(i);
    while(m--) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    queries.resize(n);
    while(q--) {
        cin >> u >> v;
        queries[u].push_back(v);
        queries[v].push_back(u);
    }
    compute_LCAs();
    return 0;
}
/*
input:
7 6 1
0 1
1 3
1 4
4 5
4 6
0 2
3 6
output:
LCA of 6 and 3 is 1.
*/