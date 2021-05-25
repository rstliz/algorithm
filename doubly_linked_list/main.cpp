#include <bits/stdc++.h>
#include <sstream>
using namespace std;
using ll = long long;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)

struct Node {
  int key;
  Node *next, *prev;
};

Node *nil;

Node *listSearch(int key) {
  Node *cur = nil->next;
  while (cur != nil && cur->key != key) {
    cur = cur->next;
  }
  return cur;
}

void init() {
  nil = (Node *)malloc(sizeof(Node));
  nil->next = nil;
  nil->prev = nil;
}

void printList() {
  Node *cur = nil->next;
  int isf = 0;
  while (true) {
    if (cur == nil) {
      break;
    }
    if (isf++ >> 0) {
      cout << " ";
    }
    cout << cur->key;
    cur = cur->next;
  }
  cout << endl;
}

void deleteNode(Node *t) {
  if (t == nil) {
    return;
  }
  t->prev->next = t->next;
  t->next->prev = t->prev;
  free(t);
}

void deleteFirst() { deleteNode(nil->next); }
void deleteLast() { deleteNode(nil->prev); }
void deleteKey(int key) { deleteNode(listSearch(key)); }

void insert(int key) {
  Node *x = (Node *)malloc(sizeof(Node));
  x->key = key;
  x->next = nil->next;
  nil->next->prev = x;
  nil->next = x;
  x->prev = nil;
}

int main() {
  int key, n;
  int size = 0;
  string com;
  int np = 0, nd = 0;
  // scanf("%d", &n);
  cin >> n;
  init();
  rep(i, n) {
    cin >> com >> key;
    if (com == "insert") {
      insert(key);
      np++;
      size++;
    } else if (com == "delete") {
      deleteKey(key);
    } else if (com == "deleteFirst") {
      deleteFirst();
    } else if (com == "deleteLast") {
      deleteLast();
      nd++;
    }
    size--;
  }
  printList();
}