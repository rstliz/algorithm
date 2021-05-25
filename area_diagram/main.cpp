#include <bits/stdc++.h>
#include <sstream>
using namespace std;
using ll = long long;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)

int main() {
  stack<int> S1;
  stack<pair<int, int>> S2;
  char ch;
  int sum = 0;
  for (int i = 0; cin >> ch; i++) {
    if (ch == '\\') {
      S1.push(i);
    } else if (ch == '/' && S1.size() > 0) {
      int j = S1.top();
      S1.pop();
      int a = i - j;
      sum += a;

      while (S2.size() > 0 && S2.top().first > j) {
        a += S2.top().second;
        S2.pop();
      }
      S2.push(make_pair(j, a));
    }
  }
  vector<int> ans;
  while (S2.size() > 0) {
    ans.push_back(S2.top().second);
    S2.pop();
  }
  reverse(ans.begin(), ans.end());
  cout << sum << endl;
  cout << ans.size();
  for (int area : ans) {
    cout << " " << area;
  }
  cout << endl;

  return 0;
}