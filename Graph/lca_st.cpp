#include <bits/stdc++.h>
using namespace std;

// LCA algorithm with Segment Tree
// query: O(logN); preprocessing: O(N) 

struct LCA {
    vector<int> euler, furst, height, st;
    vector<bool> vis;
    int n, m;

    // constructor LCA
    LCA(vector<vector<int>>& adj, int root=0) {
        n = adj.size();
        vis.assign(n, false);
        furst.resize(n);
        height.resize(n);
        dfs(adj, root);
        m = euler.size();
        st.resize(m*4);
        build();
    }

    // euler tour dfs
    void dfs(vector<vector<int>>& adj, int node, int h=0)
    {
        vis[node] = true;
        height[node] = h;
        furst[node] = euler.size();
        euler.push_back(node);
        for(int to : adj[node]) {
            if(!vis[to]) {
                dfs(adj, to, h+1);
                euler.push_back(node);
            }
        }
    }

    // segment tree for rmq
    void build() {
        for(int i = 0; i < m; i++)
            st[m+i] = euler[i];
        for(int i = m-1; i >= 0; i--) {
            int l = st[2*i], r = st[2*i+1];
            st[i] = (height[l] < height[r] ? l : r);
        }
    }

    int query(int l, int r) {
        int res = 1e9;
        for(l+=m, r+=m; l < r; l>>=1, r>>=1) {
            if(l & 1) {
                int node = st[l++];
                if(res != 1e9 && height[res] > height[node])
                    res = node;
                if(res == 1e9) res = node;
            }
            if(r & 1) {
                int node = st[--r];
                if(res != 1e9 && height[res] > height[node])
                    res = node;
                if(res == 1e9) res = node;
            }
        }
        return res;
    }

    // lca func
    int lca(int u, int v) {
        int l = furst[u], r = furst[v];
        if(l > r) swap(l, r);
        return query(l, r);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m, q, u, v;
    cin >> n >> m >> q;
    vector<vector<int>> adj(n);
    while(m--) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    LCA l(adj);
    while(q--) {
        cin >> u >> v;
        cout << l.lca(u, v) << '\n';
    }
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
1
*/
