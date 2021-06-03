#include <bits/stdc++.h>
#include <sstream>
using namespace std;
using ll = long long;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)

#define MAX 100000

struct Card {
  char suit;
  int value;
};

int n;

int _partition(Card c[], int p, int r) {
  Card x = c[r];
  int i = p - 1;
  for (int j = p; j < r; ++j) {
    if (c[j].value <= x.value) {
      ++i;
      swap(c[i], c[j]);
    }
  }
  swap(c[i + 1], c[r]);
  return i + 1;
}

void quick_sort(Card c[], int p, int r) {
  if (p < r) {
    int q = _partition(c, p, r);
    quick_sort(c, p, q - 1);
    quick_sort(c, q + 1, r);
  }
}

int main() {
  cin >> n;
  Card C[MAX];
  rep(i, n) cin >> C[i].suit >> C[i].value;
  quick_sort(C, 0, n - 1);

  rep(i, n) { cout << C[i].suit << " " << C[i].value << endl; }
}