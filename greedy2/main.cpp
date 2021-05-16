#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define repd(i, n) for (ll i = n - 1; i >= 0; i--)
#define rrepd(i, n) for (ll i = n; i >= 1; i--)

const int MAX_N = 100000;
int N, S[MAX_N], T[MAX_N];
pair<int, int> itv[MAX_N];

int main() {
  cin >> N;
  rep(i, N) { cin >> S[i]; }
  rep(i, N) { cin >> T[i]; }

  rep(i, N) {
    itv[i].first = T[i];
    itv[i].second = S[i];
  }
  sort(itv, itv + N);

  int ans = 0, t = 0;
  rep(i, N) {
    if (t < itv[i].second) {
      ans++;
      t = itv[i].first;
    }
  }
  cout << ans << endl;
}