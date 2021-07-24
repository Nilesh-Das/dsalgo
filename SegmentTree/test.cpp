#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    vector<int> v = {1,2,3,4};
    cout << lower_bound(v.begin(), v.end(), 2)-v.begin() << '\n';
}
