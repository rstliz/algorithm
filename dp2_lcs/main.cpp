#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)

int dp[1000 + 1][1000 + 1];

int main() {
  int n, m;
  string S, T;
  cin >> n >> m;
  cin >> S >> T;

  int ans = 0;
  rep(i, n) {
    rep(j, n) {
      if (S[i] == T[j]) {
        dp[i + 1][j + 1] = dp[i][j] + 1;
      } else {
        dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
      }
    }
  }

  cout << dp[n][m] << endl;
}