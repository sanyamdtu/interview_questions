#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *right, *left;
};
node *merge(node *&a, node *&b)
{
    if (!a)
        return b;
    if (!b)
        return a;
    node *p = a->right;
    node *q = b->right;
    a->right = q;
    q->left = a;
    b->right = p;
    p->left = b;
    return q;
}
node *func(node *root)
{
    if (!root)
        return root;
    node *l = func(root->left);
    node *r = func(root->right);
    root->right = root->left = root;
    node *a = merge(l, root);
    a = merge(a, r);
    return a;
}
node *temp;
node *heap(int n)
{
    if (n == 0)
        return NULL;
    node *a = temp;
    temp = temp->right;
    a->left = heap(n / 2);
    a->right = heap(n - (n / 2) - 1);
    return a;
}
int main()
{
    node *root;
    node *h = func(root)->right;
    h->left->right = NULL;
    h->left = NULL;
}