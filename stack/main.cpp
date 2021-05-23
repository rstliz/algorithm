#include <bits/stdc++.h>
#include <sstream>
using namespace std;
using ll = long long;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)

int S[1000];
int top = 0;

void push(int x) { S[++top] = x; }

int pop() { return S[top--]; }

int main() {
  int a, b = 0;
  string s;
  while (cin >> s) {
    if (s == "+") {
      a = pop();
      b = pop();
      push(a + b);
    } else if (s == "-") {
      b = pop();
      a = pop();
      push(a - b);
    } else if (s == "*") {
      a = pop();
      b = pop();
      push(a * b);

    } else {
      push(atoi(s.c_str()));
    }
  }

  cout << pop() << endl;
}