#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/contest/510/problem/B

vector<vector<int>> grid, vis;
vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
int n, m;

void fuckingyes() {
    cout << "Yes\n";
    exit(0);
}

void dfs(int x, int y, int px, int py, int c) {
    if(vis[x][y]) fuckingyes();
    vis[x][y] = 1;
    for(auto d : dir) {
        int nx = x + d[0];
        int ny = y + d[1];
        if(nx==px && ny==py) continue;
        if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
        if(grid[nx][ny] != c) continue;
        dfs(nx, ny, x, y, c);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;

    grid.resize(n, vector<int>(m));
    vis.resize(n, vector<int>(m));
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            char c;
            cin >> c;
            grid[i][j] = c-'A';
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(!vis[i][j]) dfs(i, j, -1, -1, grid[i][j]);
        }
    }
    cout << "No\n";

    return 0;
}