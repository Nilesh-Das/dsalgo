#include <bits/stdc++.h>
using namespace std;

// Range Update and Point Query

vector<int> bit;
int n;

void add(int i, int val) {
	for(++i; i<n; i += i&-i)
		bit[i] += val;
}

void add(int l, int r, int val) {
	add(l, val);
	add(r+1, -val);
}

int point_qry(int i) {
	int res = 0;
	for(++i; i>0; i -= i&-i)
		res += bit[i];
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;
	bit.assign(n+1, 0);
	for(int x, i=0; i<n; i++) {
		cin >> x;
		add(i, x);
	}
	cout << point_qry(3) << '\n';
	return 0;
}