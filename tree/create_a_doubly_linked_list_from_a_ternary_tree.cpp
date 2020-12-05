#include <bits/stdc++.h>
using namespace std;
struct node
{
    node *left, *right, *mid;
    int data;
};
node *merge(node *a, node *b, node *c)
{
    //b is  head of 2nd dll and  and a is tail of 1st dll and c is tail of the 2nd dll
    if (!b)
    {
        return a;
    }

    if (!a)
    {
        return c;
    }

    a->right = b;
    b->left = a;

    return c;
}
node *func(node *root)
{
    if (!root)
        return root;
    node *l = func(root->left);
    node *m = func(root->mid);
    node *r = func(root->right);
    node *a = merge(root, root->left, l);
    node *a = merge(a, root->mid, m);
    node *a = merge(a, root->right, r);
    root->mid = NULL;
    root->left = NULL;
    a->right = NULL;
    return a;
    //it returns tail of the dll
}
int main()
{
}