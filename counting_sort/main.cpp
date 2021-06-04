#include <bits/stdc++.h>
#include <sstream>
using namespace std;
using ll = long long;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)

#define MAX 10000

int main() {
  int n;
  cin >> n;
  vector<int> A(n + 1), B(n + 1);

  int C[MAX + 1];
  rep(i, MAX + 1) C[i] = 0;
  rep(i, n) {
    cin >> A[i + 1];
    C[A[i + 1]]++;
  }

  reps(i, 1, MAX + 1) C[i] = C[i] + C[i - 1];
  for (int j = 1; j <= n; ++j) {
    B[C[A[j]]] = A[j];
    C[A[j]]--;
    // printf("j=%d A=%d C=%d B=%d\n", j, A[j], C[A[j]], B[C[A[j]]]);
  }
  reps(i, 1, n + 1) {
    if (i > 1)
      cout << " ";
    cout << B[i];
  }
  cout << endl;
}