#include <bits/stdc++.h>
using namespace std;

struct tree {
    int v;
    tree *l = NULL;
    tree *r = NULL;
};

tree *insert(tree *r, tree *node) {
    if (r == NULL) return node;
    if (r->v > node->v)
        r->l = insert(r->l, node);
    else
        r->r = insert(r->r, node);
    return r;
}

void postorder(tree *r) {
    if (r != NULL) {
        postorder(r->l);
        postorder(r->r);
        printf("%d\n", r->v);
    }
}

int main() {
    tree *root = NULL;
    int v;
    while (scanf(" %d", &v) != EOF) {
        tree *t = new tree;
        t->l = t->r = NULL;
        t->v = v;
        root = insert(root, t);
    }
    postorder(root);
    return 0;
}

