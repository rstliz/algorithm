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

int compute_height(int u) {
  int h1 = 0, h2 = 0;
  if (T[u].right != NIL) {
    h1 = compute_height(T[u].right) + 1;
  }
  if (T[u].left != NIL) {
    h2 = compute_height(T[u].left) + 1;
  }
  return max(h1, h2);
}

void print(int u) {
  int parent_id = T[u].parent;
  int sibling = NIL;
  if (parent_id != NIL) {
    if (u == T[parent_id].left) {
      sibling = T[parent_id].right;
    }
    if (u == T[parent_id].right) {
      sibling = T[parent_id].left;
    }
  }

  int degree = 0;
  if (T[u].left != NIL)
    ++degree;
  if (T[u].right != NIL)
    ++degree;

  int depth = 0;
  for (int c = u; T[c].parent != NIL; c = T[c].parent) {
    depth++;
  }

  string type = "internal node";
  if (T[u].parent == NIL)
    type = "root";
  else if (T[u].left == NIL)
    type = "leaf";

  int height = compute_height(u);
  printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height "
         "= %d, %s\n",
         u, T[u].parent, sibling, degree, depth, height, type.c_str());
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

  rep(i, n) print(i);
  return 0;
}