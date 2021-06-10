#include <bits/stdc++.h>
#include <climits>
using namespace std;

int cache[INT_MAX];

int fib(int n) {
  if (n <= 1) {
    return 1;
  }
  if (cache[n]) {
    return cache[n];
  }
  cache[n] = fib(n - 1) + fib(n - 2);
  return cache[n];
}

int main() {
  int n;

  cin >> n;
  cout << fib(n) << endl;
}