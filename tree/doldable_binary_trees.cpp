#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    node *right, *left;
};
bool f(Node *a, Node *b)
{
    if (!a && !b)
        return true;
    if (!a || !b)
        return false;
    bool l = f(a->left, b->right);
    bool r = f(a->right, b->left);
    if (!l || !r)
        return false;
    return true;
}
int main()
{
}