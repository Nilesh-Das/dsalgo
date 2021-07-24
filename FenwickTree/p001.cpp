// Range Set Query
// https://atcoder.jp/contests/abc174/tasks/abc174_f
#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct binary_indexed_tree{
	int N;
	vector<T> BIT;
	binary_indexed_tree(int n){
		N = 1;
		while (N < n){
			N *= 2;
		}
		BIT = vector<T>(N + 1, 0);
	}
	void add(int i, T x){
		i++;
		while (i <= N){
			BIT[i] += x;
			i += i & -i;
		}
	}
	T sum(int i){
		T ans = 0;
		while (i > 0){
			ans += BIT[i];
			i -= i & -i;
		}
		return ans;
	}
	T query(int L, int R){
		return sum(R) - sum(L);
	}
	T all(){
		return BIT[0];
	}
};
int main(){
  int N, Q;
  cin >> N >> Q;
  vector<int> c(N);
  for (int i = 0; i < N; i++){
    cin >> c[i];
    c[i]--;
  }
  vector<tuple<int, int, int>> query(Q);
  for (int i = 0; i < Q; i++){
    int l, r;
    cin >> l >> r;
    l--;
    query[i] = make_tuple(r, l, i);
  }
  sort(query.begin(), query.end());
  vector<int> last(N, -1);
  binary_indexed_tree<int> BIT(N);
  vector<int> ans(Q);
  int R = 0;
  for (int i = 0; i < Q; i++){
    int l = get<1>(query[i]);
    int r = get<0>(query[i]);
    int id = get<2>(query[i]);
    while (R < r){
      if (last[c[R]] != -1){
        BIT.add(last[c[R]], -1);
      }
      last[c[R]] = R;
      BIT.add(R, 1);
      R++;
    }
    ans[id] = BIT.query(l, r);
  }
  for (int i = 0; i < Q; i++){
    cout << ans[i] << endl;
  }
}
