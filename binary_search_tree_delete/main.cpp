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

Node *tree_minimum(Node *x) {
  while (x->left != NIL) {
    x = x->left;
  }
  return x;
}

Node *tree_successor(Node *x) {
  if (x->right != NIL) {
    return tree_minimum(x->right);
  }

  Node *y = x->parent;
  while (y != NIL && x == y->right) {
    x = y;
    y = y->parent;
  }
  return y;
}

/**
 * 削除対象ノードに左右どちらかに子がいない場合、削除対象ノードに割り当てられたアドレスを解放する
 * 左右どちらにも子がいる場合、右の子のキーを削除対象ノードのキーに入れ替えた後、削除対象ノードに割り当てられたアドレスを解放する
 *
 */
void tree_delete(Node *z) {
  Node *target;
  Node *target_child;

  target = (z->left == NIL || z->right == NIL) ? z : tree_successor(z);

  target_child = (target->left != NIL) ? target->left : target->right;

  if (target_child != NIL) {
    target_child->parent = target->parent;
  }

  if (target->parent == NIL) {
    root = target_child;
  } else {
    if (target == target->parent->left) {
      target->parent->left = target_child;
    } else {
      target->parent->right = target_child;
    }
  }

  if (target != z) {
    z->key = target->key;
  }

  free(target);
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
    } else if (com == "delete") {
      cin >> x;
      tree_delete(find(root, x));
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