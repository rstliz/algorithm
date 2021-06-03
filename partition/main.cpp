#include <bits/stdc++.h>
#include <sstream>
using namespace std;
using ll = long long;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)

#define MAX 100000
int A[MAX + 1];
ll n;

int partition(int A[], int p, int r) {
  int x = A[r];
  int i = p - 1;
  for (int j = p; j < r - 1; ++j) {
    if (A[j] <= x) {
      ++i;
      swap(A[i], A[j]);
    }
  }
  swap(A[i + 1], A[r]);
  return i + 1;
}

int main() {
  cin >> n;
  rep(i, n) cin >> A[i];

  int q = partition(A, 0, n - 1);

  rep(i, n) {
    if (i)
      cout << " ";
    if (i == q)
      cout << "[";
    cout << A[i];
    if (i == q)
      cout << "]";
  }
  cout << endl;
}