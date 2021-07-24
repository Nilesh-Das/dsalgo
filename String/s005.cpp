#include <bits/stdc++.h>
#define ll int64_t
using namespace std;

// Rabin Karp Algorithm
vector<int> rabin_karp(string const& s, string const& t) {
    const int p = 31; 
    const int m = 1e9 + 9;
    int S = s.size(), T = t.size();

    vector<ll> p_pow(max(S, T)); 
    p_pow[0] = 1; 
    for (int i = 1; i < (int)p_pow.size(); i++) 
        p_pow[i] = (p_pow[i-1] * p) % m;

    vector<ll> h(T + 1, 0); 
    for (int i = 0; i < T; i++)
        h[i+1] = (h[i] + t[i] * p_pow[i]) % m; 
    ll h_s = 0; 
    for (int i = 0; i < S; i++) 
        h_s = (h_s + s[i] * p_pow[i]) % m; 

    vector<int> occurences;
    for (int i = 0; i + S - 1 < T; i++) { 
        ll cur_h = (h[i+S] + m - h[i]) % m; 
        if (cur_h == h_s * p_pow[i] % m)
            occurences.push_back(i);
    }
    return occurences;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    string patt, text;
    cin >> patt >> text;
    cout << patt << '\n';
    cout << text << '\n';
    for(int x : rabin_karp(patt, text)) {
        cout << x << ' ';
    }
    cout << '\n';
    
    return 0;
}