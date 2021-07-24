// Segment Tree
// Iterative range min query, point update at index

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int N = 1e5;  // limit for array size
int n;  // array size
int t[2 * N];

void build() {  // build the tree
	for(int i = n - 1; i > 0; --i)
		t[i] = min(t[i<<1], t[i<<1|1]);
}

void modify(int p, int value) {// set value at position p
	for(t[p += n] = value; p > 1; p >>= 1)
		t[p>>1] = min(t[p], t[p^1]);
}

int query(int l, int r) {  // sum on interval [l, r)
	int res = INT_MAX;
	for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if (l&1) res = min(res,t[l++]);
		if (r&1) res = min(res,t[--r]);
	}
	return res;
}

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		scanf("%d", t + n + i);
	build();
	printf("%d\n", query(4, 6));
	for(int i=0; i<n; i++)
		printf("%d ", t[n+i]);
	return 0;
}