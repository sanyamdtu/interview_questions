#include <bits/stdc++.h>
using namespace std;
struct node
{
    node *right, *left;
    int data;
};
int pre[1000], post[1000];
unordered_map<int, int> emap, omap;
node *func(int s, int e, int ps, int pe)
{
    if (s > e || ps > pe)
        return NULL;
    node *root = new node;
    root->data = pre[s];
    if (s == e || ps == pe)
    {
        return root;
    }

    root->left = func(s + 1, emap[post[pe - 1]] - 1, ps, omap[pre[s + 1]]);
    root->right = func(emap[post[pe - 1]], e, omap[pre[s + 1]] + 1, pe - 1);
    return root;
}
void t(node *root)
{
    if (!root)
        return;

    t(root->left);
    t(root->right);
    cout << root->data << " ";
}
int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> pre[i];
        emap[pre[i]] = i;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> post[i];
        omap[post[i]] = i;
    }
    t(func(0, n - 1, 0, n - 1));
}
