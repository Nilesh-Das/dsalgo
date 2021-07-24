// generate all substrings of string
// number of substrings
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void cnt(string s) {
  int n = s.length();
  cout << n*(n+1)/2 << '\n';
}

void gen(string s) {
  int n = s.length();
  for(int i=0; i<n; i++) {
    for(int j=i; j<n; j++) {
      cout << s.substr(i, j-i+1) << '\n';
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  string s = "abc";
  gen(s);
  // cnt(s);
  
  return 0;
}