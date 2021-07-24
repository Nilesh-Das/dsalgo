#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fi first
#define se second
#define pb push_back
#define mp make_pair
/*

Problems:
https://codeforces.com/contest/59/problem/E
https://codeforces.com/contest/796/problem/D
https://codeforces.com/contest/821/problem/D
https://codeforces.com/contest/653/problem/E
https://codeforces.com/contest/769/problem/C

*/
const int N = 1e5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<vector<int>> adj; // adj list
    int n, s; // #nodes #src_vertex


    // Breadth first search
    // some book keeping stuff
    queue<int> q; // temp keeps adj nodes to be process
    vector<bool> vis(n); // keeps #nodes visited or not
    vector<int> dist(n), par(n); // keeps parent nodes

    // initialisation with src vertex
    q.push(s);
    vis[s] = true;
    par[s] = -1;

    // Characterstic loop of bfs
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(auto v : adj[u]) {
            if(!vis[v]) {
                vis[v] = true;
                q.push(v);
                dist[v] = dist[u] + 1;
                par[v] = u;
            }
        }
    }

    // Displaying of shortest path
    if(!used[u])
        cout << "No Path!";
    else {
        vector<int> path;
        for(int v = u; v != -1; v = par[v])
            path.push_back(v);
        reverse(path.begin(), path.end());
        cout << "Path: ";
        for(int v : path)
            cout << v << ' ';
    }
    return 0;
}