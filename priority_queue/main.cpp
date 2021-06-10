#include <bits/stdc++.h>
#include <sstream>
using namespace std;
using ll = long long;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)

#define MAX 2000000000
#define INFTY (1 << 30)

int H = 0, A[MAX + 1];

void max_heapify(int i) {
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
    max_heapify(largest);
  }
}

int extract_max() {
  if (H < 1) {
    return -INFTY;
  }
  int max = A[1];
  A[1] = A[H--];

  max_heapify(1);
  return max;
}

void increase_key(int i, int key) {
  if (key < A[i]) {
    return;
  }

  A[i] = key;
  while (i > 1 && A[i / 2] < A[i]) {
    swap(A[i], A[i / 2]);
    i = i / 2;
  }
}

void insert(int key) {
  H++;
  A[H] = -INFTY;
  increase_key(H, key);
}

int main() {
  int v;
  string comm;
  while (true) {
    cin >> comm;
    if (comm == "insert") {
      cin >> v;
      insert(v);
    } else if (comm == "extract") {
      cout << extract_max() << endl;
    } else if (comm == "end") {
      break;
    }
  }
}