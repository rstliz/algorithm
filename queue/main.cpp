#include <bits/stdc++.h>
#include <sstream>
using namespace std;
using ll = long long;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)

#define LEN 100005

typedef struct pp {
  char name[100];
  int t;
} P;

P Q[LEN];
int head, tail, n;

void enqueue(P x) {
  Q[tail] = x;
  tail = (tail + 1) % LEN;
}

P dequeue() {
  P x = Q[head];
  head = (head + 1) % LEN;
  return x;
}

int main() {
  int elaps = 0, c;
  int i, quantum;
  P u;
  cin >> n >> quantum;
  for (int i = 0; i < n; ++i) {
    cin >> Q[i].name;
    cin >> Q[i].t;
  }
  head = 0;
  tail = n;

  while (head != tail) {
    u = dequeue();
    c = min(quantum, u.t);
    u.t -= c;
    elaps += c;

    if (u.t > 0) {
      enqueue(u);
    } else {
      cout << u.name << " " << elaps << endl;
    }
  }
  return 0;
}