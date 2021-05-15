#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
template <typename T> inline bool chmax(T &a, const T &b) {
  bool compare = a < b;
  if (a < b)
    a = b;
  return compare;
}

int main() {
  int n;
  cin >> n;
  int a[100];

  rep(i, n) { cin >> a[i]; }
  int ans = 0;

  rep(i, n) {
    cin >> a[i];
    reps(j, i + 1, n) {
      reps(k, j + 1, n) {
        int len = a[i] + a[j] + a[k];
        int ma = max({a[i], a[j], a[k]});
        int rest = len - ma;
        if (ma < rest) {
          ans = max({ans, len});
        }
      }
    }
  }
  cout << ans << endl;
}