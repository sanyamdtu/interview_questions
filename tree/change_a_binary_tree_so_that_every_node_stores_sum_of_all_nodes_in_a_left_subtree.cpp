#include <bits/stdc++.h>
using namespace std;
struct node
{
    node *left, *right;
    int data;
};
int sum(node *root)
{
    if (!root)
        return 0;
    int l = sum(root->left);
    int ans = l + sum(root->right) + root->data;
    root->data = l;
    return ans;
}
int main()
{
}