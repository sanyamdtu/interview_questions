#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *right, *left;
};
int ans = 0;
int func(node *root)
{
    if (!root)
        return 0;
    int l = func(root->left);
    int r = func(root->right);
    int t = l + r + 1;
    if (t % 2 == 0)
        ans++, t = 0;
    return t;
}
int main()
{
}