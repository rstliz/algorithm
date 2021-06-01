#include <bits/stdc++.h>
#include <sstream>
using namespace std;
using ll = long long;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)

ll n;
vector<ll> A;

bool solve(int i, int m) {
  // cout << "i:" << i << " m:" << m << " A[i]:" << A[i] << endl;
  if (m == 0) {
    return true;
  }
  if (i >= n) {
    return false;
  }
  return solve(i + 1, m) || solve(i + 1, m - A[i]);
}

int main() {
  ll q, m;
  cin >> n;
  rep(i, n) {
    int t;
    cin >> t;
    A.push_back(t);
  }
  cin >> q;
  rep(i, q) {
    cin >> m;
    if (solve(0, m)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}