/*
Given a n*n matrix where all numbers are distinct, find the maximum length path
(starting from any cell) such that all cells along the path are in increasing
order with a difference of 1.

We can move in 4 directions from a given cell (i, j), i.e., we can move to 
(i+1, j) or (i, j+1) or (i-1, j) or (i, j-1) with the condition that the adjacent
cells have a difference of 1.

Example:

input:
3
1 2 9
5 3 8
4 6 7

output:
4

Explanation : 6->7->8->9
*/
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int n;
vector<vector<int>> a;
vector<vector<int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};
vector<vector<int>> dp;

int longestPath(int r, int c) {
  if(dp[r][c]!=-1) return dp[r][c];
  int dp_max = -INF;
  for(auto move : dir) {
    int x = r + move[0];
    int y = c + move[1];
    if(x<0||x>=n||y<0||y>=n) continue;
    if(a[r][c]+1!=a[x][y]) continue;
    dp_max = max(dp_max, longestPath(x,y)+1);
  }
  return dp[r][c]=dp_max;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
  cin >> n;
  a.resize(n, vector<int>(n));
  dp.resize(n, vector<int>(n, -1));
  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
      cin >> a[i][j];

  int ans = 0;
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      if(dp[i][j]==-1) longestPath(i,j);
      ans = max(ans, dp[i][j]);
    }
  }
  cout << ans << '\n';

	return 0;
}

