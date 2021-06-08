#include <bits/stdc++.h>
#include <sstream>
using namespace std;
using ll = long long;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)

int main() {
  int H;
  cin >> H;
  vector<int> A(H + 1);

  reps(i, 1, H + 1) { cin >> A[i]; }

  reps(i, 1, H + 1) {
    cout << "node " << i << ": ";
    cout << "key = " << A[i] << ", ";
    if (floor(i / 2) > 0) {
      cout << "parent key = " << int(A[i / 2]) << ", ";
    }
    if (i * 2 < H) {
      cout << "left key = " << A[i * 2] << ", ";
      cout << "right key = " << A[i * 2 + 1] << ", ";
    }
    cout << endl;
  }
}