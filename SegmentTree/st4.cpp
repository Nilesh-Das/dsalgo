// Segment Tree with Lazy Propagation
// Range sum update, Range sum query

#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5+1;
int ar[N], st[4*N], lz[4*N];

void build(int si, int ss, int se) {
	if(ss == se) {
		st[si] = ar[ss];
		return;
	}

	int mid = (ss + se) / 2;

	build(2*si, ss, mid);
	build(2*si+1, mid+1, se);

	st[si] = st[2*si] + st[2*si+1];
}

void push(int si, int ss, int se) {
	if(lz[si]!=0) {
		int dx = lz[si];
		lz[si] = 0;
		st[si] += dx * (se - ss + 1);

		if(ss != se)
			lz[2*si] += dx, lz[2*si+1] += dx;
	}
}

int query(int si, int ss, int se, int qs, int qe) {
	push(si, ss, se);

	if(ss > qe || se < qs) return 0;

	if(ss >= qs && se <= qe) return st[si];

	int mid = (ss + se) / 2;
	return query(2*si, ss, mid, qs, qe) + query(2*si+1, mid+1, se, qs, qe);
}

void update(int si, int ss, int se, int qs, int qe, int val) {
	push(si, ss, se);

	if(ss > qe || se < qs) return;

	if(ss >= qs && se <= qe) {
		st[si] += val * (se - ss + 1);

		if(ss != se)
			lz[2*si] += val, lz[2*si+1] += val;
		return;
	}

	int mid = (ss + se) / 2;
	update(2*si, ss, mid, qs, qe, val);
	update(2*si+1, mid+1, se, qs, qe, val);

	st[si] = st[2*si] + st[2*si+1];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, q, code, l, r, val;
	cin >> n >> q;
	for(int i=1; i<=n; i++)
		cin >> ar[i];
	build(1, 1, n);

	while(q--) {
		cin >> code;
		if(code == 1) {
			cin >> l >> r;
			cout << query(1, 1, n, l, r) << '\n';
		} else {
			cin >> l >> r >> val;
			update(1, 1, n, l, r, val);
		}
	}
	
	return 0;
}

/*
input:
5 5
1 2 3 4 5
1 1 1
1 1 5
2 1 3 1
1 1 1
1 1 5

output:
1
15
2
18

*/