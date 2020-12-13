#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *right, *left;
};
node *insert(node *&root, int x)
{
    node *a = new node;
    a->data = x;
    a->left = a->right = NULL;
    if (!root)
    {
        return a;
    }
    node *temp = root;
    while (1)
    {
        if (root->data > x)
        {
            if (!root->left)
            {
                root->left = a;
                return temp;
            }
            root = root->left;
        }
        else
        {
            if (!root->right)
            {
                root->right = a;
                return temp;
            }
            root = root->right;
        }
    }
}
int l, r;
node *func(node *root)
{
    if (!root)
        return NULL;
    root->right = func(root->right);
    root->left = func(root->left);
    if (root->data >= l && root->data <= r)
        return root;
    else if (root->data < l)
        return func(root->right);
    else
        return func(root->left);
}
void pre(node *root)
{
    if (!root)
        return;
    pre(root->left);
    cout << root->data << " ";
    pre(root->right);
}
int main()
{
    node *head = NULL;
    int x;

    while (1)
    {
        cin >> x;
        if (x == -1)
            break;
        head = insert(head, x);
    }
    pre(head);
    cin >> l >> r;
    pre(func(head));
}