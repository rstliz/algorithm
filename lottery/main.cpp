#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define YesNo(bool)                                                            \
  if (bool) {                                                                  \
    cout << "Yes" << endl;                                                     \
  } else {                                                                     \
    cout << "No" << endl;                                                      \
  }

static bool binary_search(int x, vector<int> kk) {
  int l = 0, r = kk.size();

  while (r - l >= 1) {
    int i = (l + r) / 2;
    if (kk[i] == x) {
      return true;
    } else if (kk[i] < x) {
      l += i;
    } else {
      r = i;
    }
  }
  return false;
}

int main() {
  int n, m;

  cin >> n >> m;
  vector<int> k(n);
  vector<int> kk(n * n);

  rep(i, n) { cin >> k.at(i); }

  rep(c, n) {
    rep(d, n) { kk[c * n + d] = k[c] + k[d]; }
  }

  bool f = false;
  rep(a, n) {
    rep(b, n) {
      if (binary_search(m - k[a] - k[b], kk)) {
        f = true;
      }
    }
  }
  YesNo(f);
}