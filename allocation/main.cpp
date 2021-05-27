#include <bits/stdc++.h>
#include <sstream>
using namespace std;
using ll = long long;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define MAX 100000

int n, k;
ll T[MAX];

int countItemUnderWeight(ll maxWeight) {
  int i = 0;
  for (int j = 0; j < k; j++) {
    ll sumWeight = 0;
    while (sumWeight + T[i] <= maxWeight) {
      sumWeight += T[i];
      i++;
      if (i == n) {
        return n;
      }
    }
  }
  return i;
}

ll solve() {
  ll left = 0, right = MAX * 10000;
  ll mid;
  while (right - left > 1) {
    mid = (left + right) / 2;
    int v = countItemUnderWeight(mid);
    if (v >= n) {
      right = mid;
    } else {
      left = mid;
    }
  }
  return right;
}

int main() {
  cin >> n >> k;
  rep(i, n) { cin >> T[i]; }
  cout << solve() << endl;
}