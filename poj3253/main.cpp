#include <bits/stdc++.h>
#include <sstream>
using namespace std;
using ll = long long;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)

int main() {
  int N;
  cin >> N;
  vector<int> L(N);
  rep(i, N) { cin >> L.at(i); }

  ll ans = 0;
  while (N > 1) {
    int mii1 = 0, mii2 = 1;
    if (L[mii1] > L[mii2]) {
      swap(mii1, mii2);
    }
    reps(i, 2, N) {
      if (L[i] < L[mii1]) {
        mii2 = mii1;
        mii1 = i;
      } else if (L[i] < L[mii2]) {
        mii2 = i;
      }
    }
    int t = L[mii1] + L[mii2];
    ans += t;

    if (mii1 == N - 1) {
      swap(mii1, mii2);
    }
    L[mii1] = t;
    L[mii2] = L[N - 1];
    N--;
  }

  cout << ans << endl;
}