// Z algorithm (Linear time pattern searching Algorithm)

#include <bits/stdc++.h>
using namespace std;


void getZarr(string str, int Z[]) {
    int n = str.length();
    int l, r, k;
    l = r = 0;
    for(int i = 0; i < n; i++) {
        if(i > r) {
            l = r = i;
            while(r < n && str[r-l]==str[r])
                r++;
            Z[i] = r-l;
            r--;
        } else {
            k = i-l;
            if(Z[k] < r-i+1)
                Z[i] = Z[k];
            else {
                l = i;
                while(r<n && str[r-l]==str[r])
                    r++;
                Z[i] = r-l;
                r--;
            }
        }
    }
}

void search(string pattern, string text) {
    string str = pattern + "$" + text;
    int l = str.length();
    int Z[l];
    getZarr(str, Z);
    for(int i = 0; i < l; i++) {
        if(Z[i] == pattern.length())
            cout << "Pattern found at index " << i-pattern.length()-1 << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string text = "GEEKS FOR GEEKS"; 
    string pattern = "GEEK";
    search(pattern, text);
    return 0;
}