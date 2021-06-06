#include <bits/stdc++.h>
#include <sstream>
using namespace std;
using ll = long long;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)

#define MAX 100005
#define NIL -1

struct Node {
  int parent, left, right;
};

Node T[MAX];

void pre_order(int u) {
  if (u == NIL) {
    return;
  }
  cout << " " << u;
  pre_order(T[u].left);
  pre_order(T[u].right);
}

void in_order(int u) {
  if (u == NIL) {
    return;
  }
  in_order(T[u].left);
  cout << " " << u;
  in_order(T[u].right);
}

void post_order(int u) {
  if (u == NIL) {
    return;
  }
  post_order(T[u].left);
  post_order(T[u].right);
  cout << " " << u;
}

int main() {
  int n, node_id, left_node_id, right_node_id;
  cin >> n;

  rep(i, n) {
    cin >> node_id >> left_node_id >> right_node_id;
    T[node_id].parent = NIL;
    rep(i, node_id) {
      if (node_id == T[i].left || node_id == T[i].right) {
        T[node_id].parent = i;
        break;
      }
    }
    T[node_id].left = left_node_id;
    T[node_id].right = right_node_id;
  }

  cout << "Preorder" << endl;
  pre_order(0);
  cout << endl;
  cout << "Inorder" << endl;
  in_order(0);
  cout << endl;
  cout << "Postorder" << endl;
  post_order(0);
  cout << endl;

  return 0;
}