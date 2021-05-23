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
  rep(i, N) {
    int minj = i;
    reps(j, i, N) {
      if (A[j] < A[minj]) {
        minj = j;
      }
    }
    swap(A[i], A[minj]);
    if (i != minj) {
      ++cnt;
    }
  }

  stringstream ss;
  rep(i, N) { ss << A[i] << " "; }
  cout << ss.str() << endl;
  cout << cnt << endl;
}