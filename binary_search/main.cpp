#include <bits/stdc++.h>
#include <sstream>
using namespace std;
using ll = long long;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)

bool binary_search(int x, vector<int> heystack) {
  ll left = 0, right = heystack.size();
  while (left < right) {
    ll middle = (left + right) / 2;
    if (x == heystack[middle]) {
      return true;
    } else if (x < heystack[middle]) {
      right = middle;
    } else if (x > heystack[middle]) {
      left = middle + 1;
    }
  }
  return false;
}

int main() {
  ll n, q;
  cin >> n;
  vector<int> S(n);
  rep(i, n) { cin >> S[i]; }
  cin >> q;
  vector<int> T(q);
  rep(i, q) { cin >> T[i]; }

  ll ans = 0;
  for (int x : T) {
    if (binary_search(x, S)) {
      ans++;
    }
  }
  cout << ans << endl;
}