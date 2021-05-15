#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)

int main() {
  int l, n;

  cin >> l >> n;
  vector<int> x(n);

  rep(i, n) { cin >> x.at(i); }

  int min_ans = 0;
  int max_ans = 0;
  rep(i, n) {
    min_ans = max(min_ans, min(abs(l - x[i]), x[i]));
    max_ans = max(max_ans, max(abs(l - x[i]), x[i]));
  }
  cout << min_ans << endl;
  cout << max_ans << endl;
}