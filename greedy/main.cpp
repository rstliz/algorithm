#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define repd(i, n) for (ll i = n - 1; i >= 0; i--)
#define rrepd(i, n) for (ll i = n; i >= 1; i--)

int V[6] = {1, 5, 10, 50, 100, 500};

int main() {
  int C[6];
  int A;

  rep(i, 6) { cin >> C[i]; }
  cin >> A;

  int ans = 0;
  repd(i, 6) {
    int t = min(A / V[i], C[i]);
    A -= t * V[i];
    ans += t;
  }
  cout << ans << endl;
}