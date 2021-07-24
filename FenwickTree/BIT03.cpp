#include <bits/stdc++.h>
using namespace std;

// Range Update and Range Query
vector<int> b1, b2;
int n;

void add(vector<int>& b, int i, int x) {
    for(; i<=n; i += i&-i)
        b[i] += x;
}

void range_add(int l, int r, int x) {
    add(b1, l, x);
    add(b1, r+1, -x);
    add(b2, l, x*(l-1));
    add(b2, r+1, -x*r);
}

int sum(vector<int>& b, int i) {
    int tot = 0;
    for(; i>0; i -= i&-i)
        tot += b[i];
    return tot;
}

int prefix_sum(int i) {
    return sum(b1, i)*i - sum(b2, i);
}

int range_sum(int l, int r) {
    return prefix_sum(r) - prefix_sum(l-1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    b1.assign(n+1, 0);
    b2.assign(n+1, 0);
    
    for(int x, i=1; i<=n; i++) {
        cin >> x;
        range_add(i, i, x);
    }
    
    cout << range_sum(1,4) << '\n';
    
    return 0;
}