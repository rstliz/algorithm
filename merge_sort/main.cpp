#include <bits/stdc++.h>
#include <sstream>
using namespace std;
using ll = long long;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)

#define MAX 500000
#define SENTINEL 2000000000

int L[MAX / 2 + 2], R[MAX / 2 + 2];
int cnt;

void merge(int A[], int n, int mid, int left, int right) {
  cout << "left=" << left << " mid=" << mid << " right=" << right << endl;
  int n1 = mid - left;
  int n2 = right - mid;
  rep(i, n1) L[i] = A[left + i];
  rep(i, n2) R[i] = A[mid + i];
  L[n1] = R[n2] = SENTINEL;
  int i = 0, j = 0;
  reps(k, left, right) {
    cnt++;
    if (L[i] <= R[j]) {
      A[k] = L[i++];
    } else {
      A[k] = R[j++];
    }
  }
}

void merge_sort(int A[], int n, int left, int right) {
  if (left + 1 < right) {
    int mid = (left + right) / 2;
    merge_sort(A, n, left, mid);
    merge_sort(A, n, mid, right);
    merge(A, n, mid, left, right);
  }
}

int main() {
  int A[MAX], n, i;
  cnt = 0;

  cin >> n;
  rep(i, n) cin >> A[i];

  merge_sort(A, n, 0, n);

  rep(i, n) {
    if (i)
      cout << " ";
    cout << A[i];
  }
  cout << endl;
  cout << cnt << endl;
}