#include <iostream>
using namespace std;
struct node
{
    int data;
    node *right, *left;
};
node *add(node *p, node *q)
{
    if (!p)
        return q;
    if (!q)
        return p;
    node *a = p->right;
    node *b = q->right;
    a->left = q;
    q->right = a;
    p->right = b;
    b->left = p;
    return q;
}
node *bl(node *root)
{
    if (!root)
        return NULL;
    node *l = NULL, *r = NULL;
    l = bl(root->left);
    r = bl(root->right);
    root->right = root->left = root;
    return add(add(l, root), r);
}
node *merge(node *p, node *q)
{
    if (!p)
        return q;
    if (!q)
        return p;
    if (p->data > q->data)
    {
        node *a = new node;
        a->data = q->data;
        a->right = merge(p, q->right);
        return a;
    }
    else
    {
        node *a = new node;
        a->data = p->data;
        a->right = merge(p->right, q);
        return a;
    }
}
///////////
node *temp; //temp will have head of the merged linked list
node *tree(int n)
{
    if (n == 0)
        return NULL;
    node *l = tree(n / 2);
    node *a = temp;
    temp = temp->right;
    node *r = tree(n - (n / 2) - 1);
    a->left = l;
    a->right = r;
    return a;
}
int main()
{
    return 0;
}