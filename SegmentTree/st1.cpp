// Segment Tree
// Iterative range sum query, point update at idx

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int N = 1e5;
int n, t[2*N];

void upd(int i, int val) {
	for(t[i+=n]=val; i>1; i>>=1)
		t[i>>1] = t[i] + t[i^1];
}

int qry(int l, int r) {
	int res = 0;
	for (l+=n, r+=n; l<r; l>>=1, r>>=1) {
		if(l&1) res += t[l++];
		if(r&1) res += t[--r];
	}return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;
	for(int i=0; i<n; i++)
		cin >> t[n+i];
	for(int i=n-1; i>0; --i)
		t[i] = t[i<<1]+t[i<<1|1];

	for(int i=0; i<n; i++)
		cout << t[n+i] << ' ';
	cout << '\n';

	cout << qry(1,4) << '\n';


	return 0;
}