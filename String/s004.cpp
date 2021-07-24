#include <bits/stdc++.h>
using namespace std;

/*
KMP Algorithm
0 1 2 3 4 5 6 7
A B C D A B C A

i=1, j=0, F[i]=0
i=2, j=0, F[i]=0
i=3, j=0, F[i]=0

*/

vector<int> pref_func(string z) {
  int n = z.size();
  vector<int> F(n);
  for(int i=1; i<n; i++) {
    int j = F[i-1];
    while(j && z[i] != z[j]) j = F[j-1];
    if(z[i] == z[j]) F[i]=j+1;
    else F[i] = 0;
  }
  return F;
}

int kmp(string s, string t) {
  int n = s.size();
  int m = t.size();

  vector<int> F = pref_func(t);
  int cnt = 0;
  for(int i=0, j=0; i<n; ) {
    if (s[i] == t[j]) i++, j++;
    if (j == m) { cnt++; j=F[j-1]; }
    else if (i < n && s[i] != t[j]) {
      if(j) j=F[j-1];
      else i++;
    }
  }
  return cnt;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
    
  string s, t;
  s = "asnflsn";
  t = "fls";
  cout << kmp(s, t) << '\n';
  
  return 0;
}
