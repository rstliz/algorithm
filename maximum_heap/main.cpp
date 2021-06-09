#include <bits/stdc++.h>
#include <sstream>
using namespace std;
using ll = long long;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)

#define MAX 2000000000

int H;
int A[MAX + 1];

void max_heapify(int A[], int i) {
  int largest;
  int l = i * 2;
  int r = i * 2 + 1;
  if (l <= H && A[l] > A[i]) {
    largest = l;
  } else {
    largest = i;
  }
  if (r <= H && A[r] > A[largest]) {
    largest = r;
  }

  if (largest != i) {
    swap(A[i], A[largest]);
    max_heapify(A, largest);
  }
}

int main() {
  cin >> H;

  reps(i, 1, H + 1) { cin >> A[i]; }

  for (int i = H / 2; i >= 1; i--)
    max_heapify(A, i);

  reps(i, 1, H + 1) { cout << " " << A[i]; }
  cout << endl;
}