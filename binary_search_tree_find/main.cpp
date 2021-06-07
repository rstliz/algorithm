#include <bits/stdc++.h>
#include <sstream>
using namespace std;
using ll = long long;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)

struct Node {
  int key;
  Node *parent, *left, *right;
};

Node *root, *NIL;

void insert(int k) {
  Node *y = NIL;
  Node *x = root;
  Node *z;

  z = (Node *)malloc(sizeof(Node));
  z->key = k;
  z->left = NIL;
  z->right = NIL;

  while (x != NIL) {
    y = x;
    if (z->key < x->key) {
      x = x->left;
    } else {
      x = x->right;
    }
  }
  z->parent = y;
  if (y == NIL) {
    root = z;
  } else {
    if (z->key < y->key) {
      y->left = z;
    } else {
      y->right = z;
    }
  }
}

Node *find(Node *x, int k) {
  while (x != NIL && k != x->key) {
    if (k < x->key) {
      x = x->left;
    } else {
      x = x->right;
    }
  }
  return x;
}

void pre_order(Node *u) {
  if (u == NIL) {
    return;
  }
  cout << " " << u->key;
  pre_order(u->left);
  pre_order(u->right);
}

void in_order(Node *u) {
  if (u == NIL) {
    return;
  }
  in_order(u->left);
  cout << " " << u->key;
  in_order(u->right);
}

int main() {
  int n, x;
  string com;
  cin >> n;

  rep(i, n) {
    cin >> com;

    if (com == "insert") {
      cin >> x;
      insert(x);
    } else if (com == "find") {
      cin >> x;
      printf("%s\n", find(root, x) != NIL ? "yes" : "no");
    } else if (com == "print") {
      cout << "Inorder" << endl;
      in_order(root);
      cout << endl;
      cout << "Preorder" << endl;
      pre_order(root);
      cout << endl;
    }
  }
}