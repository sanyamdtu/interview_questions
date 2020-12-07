#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *right, *left;
};
int ans, level;
void func(node *root, int f, int k)
{
    if (!root->left && !root->right)
    {
        if (f == 0 && k > level)
        {
            ans = root->data;
        }
        return;
    }
    if (root->left)
        func(root->left, 0, k + 1);
    if (root->right)
        func(root->right, 1, k + 1);
}
int main()
{
}