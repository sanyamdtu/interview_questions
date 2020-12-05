#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *right, *left;
};
vector<int> func(node *root)
{
    vector<int> v;
    queue<node *> q;
    while (!q.empty())
    {
        auto a = q.front();
        v.push_back(a->data);
        q.pop();
        node *b = NULL;
        if (!q.empty())
        {
            b = q.front();
            q.pop();
            v.push_back(b->data);
        }
        if (a->left)
            q.push(a->left);
        if (b && b->right)
            q.push(b->right);
        if (a->right)
            q.push(a->right);
        if (b && b->left)
            q.push(b->left);
    }
    return v;
}
int main()
{
}