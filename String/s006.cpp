#include <bits/stdc++.h>
#define ll int64_t
using namespace std;

// string hashing
// polynomial rolling hash func 
ll compute_hash(string s) {
  const int m = 1e9+9;
  const int p = 31;

  int n = s.size();
  vector<ll> p_pow(n, 1);
  for(int i=1; i<n; i++)
    p_pow[i] = (p_pow[i-1] * p) % m;

  ll hash_val = 0;
  for(int i=0; i<n; i++) 
    hash_val = (hash_val + s[i]*p_pow[i]) % m;

  return hash_val;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  string s = "asfDlsjgDsg";
  cout << compute_hash(s) << '\n';
  
  return 0;
}