#include <bits/stdc++.h>
using namespace std;
struct node
{
    node *left, *right;
    int data;
};
int x, y, z;
int func(node *root)
{
    if (root != NULL)
        return -1;
    int l = func(root->left);
    int r = func(root->right);
    if (root->data == x && root->data == y)
        return root->data;
    if ((l != -1) && (r != -1))
        return root->data;
    if (l != -1)
        return l;
    return r;
}
vector<int> v;
int func(node *root)
{
    if (!root)
        return 0;
    int l = func(root->left);
    int r = func(root->right);
    if (root->data == z && (l == 1 || r == 1))
    {
        v.push_back(root->data);
        return 1;
    }
    return 0;
}
int main()
{
    node *root;
    z = func(root);
}