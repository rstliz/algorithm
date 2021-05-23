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

  int v, j;
  rep(i, N) {
    v = A[i];
    j = i - 1;
    while (j >= 0 && A[j] > v) {
      A[j + 1] = A[j];
      j--;
    }
    A[j + 1] = v;
  }
  stringstream ss;
  rep(i, N) { ss << A[i]; }
  cout << ss.str() << endl;
}