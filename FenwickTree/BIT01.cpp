#include <bits/stdc++.h>
using namespace std;

// One based indexing Fenwick Tree

struct FenwickTree {
    vector<int> bit;
    int n;

    FenwickTree(int size) {
        this->n = size+1;
        bit.assign(size+1, 0);
    }

    FenwickTree(vector<int> a): FenwickTree(a.size()) {
        for(int i=0; i<(int)a.size(); i++)
            upd(i, a[i]);
    }

    int sum(int i) {
        int res = 0;
        for(++i; i>0; i -= i&-i)
            res += bit[i];
        return res;
    }

    void upd(int i, int val) {
        for(++i; i<n; i += i&-i)
            bit[i] += val;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l-1);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++)
        cin >> v[i];
    FenwickTree ft(v);
    cout << ft.sum(2,4) << '\n';
    return 0;
}