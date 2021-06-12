#include <bits/stdc++.h>
#include <climits>
using namespace std;

static const int N = 1000;

int lcs(string X, string Y) {
  int c[N + 1][N + 1];
  int m = X.size();
  int n = Y.size();
  int maxl = 0;

  X = ' ' + X;
  Y = ' ' + Y;
  for (int i = 0; i <= m; ++i)
    c[i][0] = 0;
  for (int j = 1; j <= n; ++j)
    c[0][j] = 0;

  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (X[i] == Y[j]) {
        c[i][j] = c[i - 1][j - 1] + 1;
      } else {
        c[i][j] = max(c[i - 1][j], c[i][j - 1]);
      }
      maxl = max(maxl, c[i][j]);
    }
  }
  return maxl;
}

int main() {
  string x, y;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    cout << lcs(x, y) << endl;
  }

  return 0;
}