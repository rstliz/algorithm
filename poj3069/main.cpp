#include <bits/stdc++.h>
#include <sstream>
using namespace std;
using ll = long long;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)

int main() {
  int N, R;
  cin >> N >> R;
  vector<int> X(N);
  rep(i, N) { cin >> X.at(i); }
  sort(X.begin(), X.end());

  int i = 0, ans = 0;
  while (i < N) {
    int s = X[i];
    while (i < N && X[i] <= s + R) {
      i++;
    }

    int p = X[i - 1];
    while (i < N && X[i] <= p + R) {
      i++;
    }
    ans++;
  }

  cout << ans << endl;
}