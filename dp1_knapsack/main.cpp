#include <bits/stdc++.h>
#include <sstream>
using namespace std;
using ll = long long;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)

int dp[100 + 1][10000 + 1];

int main() {
  int N, W;
  cin >> N >> W;
  vector<pair<int, int>> vw(N);
  rep(i, N) { cin >> vw[i].second >> vw[i].first; }
  // vector<vector<int>> dp(1000);

  int ans = 0;
  int sw = 0;

  for (int i = N - 1; i >= 0; i--) {
    for (int j = 0; j <= W; j++) {
      if (j < vw[i].second) {
        dp[i][j] = dp[i + 1][j];
      } else {
        dp[i][j] = max(dp[i + 1][j], dp[i + 1][j - vw[i].second] + vw[i].first);
      }
    }
  }

  cout << dp[0][W] << endl;
}