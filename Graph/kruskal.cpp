#include <bits/stdc++.h>
#define ll long long
using namespace std;

/*
Kruskal's algo for MST
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
6 5 1
5 4 1
1 2 1
1 3 1
4 3 1
1 0 2

*/

vector<vector<int>> edges;
vector<int> p;
int n, m, u, v, w;

int find_p(int i) {
    if(i != p[i])
        p[i] = find_p(p[i]);
    return p[i];
}

void Kruskal() {
    p.resize(n);
    for(int i=0; i<n; i++) p[i]=i;
        vector<vector<int>> mst;
    for(auto edge : edges) {
        int p_a = find_p(edge[0]);
        int p_b = find_p(edge[1]);
        if(p_a != p_b) {
            mst.push_back(edge);
            p[p_a] = p_b;
        }
    }
    for(auto edge : mst) {
        printf("%d %d %d\n", edge[0], edge[1], edge[2]);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        cin >> u >> v >> w;
        vector<int> edge1 = {u, v, w};
        vector<int> edge2 = {v, u, w};
        edges.push_back(edge1);
        edges.push_back(edge2);
    }
    sort(edges.begin(), edges.end(), [&](vector<int>a, vector<int>b) {
        return a[2] < b[2];
    });
    Kruskal();
    
    return 0;
}