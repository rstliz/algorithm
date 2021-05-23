#include <bits/stdc++.h>
#include <sstream>
using namespace std;
using ll = long long;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)

int cnt = 0;

void insert_sort(vector<int> &A, int N, int g) {
  int v, j;
  reps(i, g, N) {
    v = A[i];
    j = i - g;
    while (j >= 0 && A[j] > v) {
      A[j + g] = A[j];
      j -= g;
    }
    A[j + g] = v;
  }
}

void shell_sort(vector<int> &A, int N) {
  cnt = 0;
  int m = N / 2 + 1;
  cout << m << endl;
  vector<int> G;
  for (int h = 0;;) {
    if (h > N) {
      break;
    }
    G.push_back(h);
    h = 3 * h + 1;
  }

  for (int i = G.size() - 1; i >= 0; --i) {
    insert_sort(A, N, G[i]);
  }
}

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  rep(i, N) { cin >> A[i]; }
  shell_sort(A, N);

  stringstream ss;
  rep(i, N) { ss << A[i]; }
  cout << ss.str() << " " << endl;
}