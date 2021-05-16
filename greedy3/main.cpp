#include <bits/stdc++.h>
#include <sstream>
using namespace std;
using ll = long long;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)

int main() {
  int N;
  string S;
  cin >> N;
  cin >> S;
  std::stringstream T;
  int l = 0, r = N - 1;

  while (l <= r) {
    if (S.at(l) < S.at(r)) {
      T << S.at(l++);
    } else {
      T << S.at(r--);
    }
  }
  cout << T.str() << endl;
}