#include <bits/stdc++.h>
#include <sstream>
using namespace std;
using ll = long long;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  rep(i, N) { cin >> A[i]; }

  int cnt = 0;
  bool flag = true;
  for (int i = 0; flag; ++i) {
    flag = false;
    for (int j = N - 1; j > i; --j) {
      if (A[j] < A[j - 1]) {
        swap(A[j], A[j - 1]);
        flag = true;
        ++cnt;
      }
    }
  }

  stringstream ss;
  rep(i, N) { ss << A[i] << " "; }
  cout << ss.str() << endl;
  cout << cnt << endl;
}