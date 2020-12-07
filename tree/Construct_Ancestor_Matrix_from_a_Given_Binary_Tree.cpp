#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *right, *left;
};
int mat[200][200];
int n;
void func(node *root, int p)
{
    if (!root)
        return;
    mat[root->data][p] = 1;
    for (int i = 0; i < n; i++)
    {
        if (mat[i][p] == 1)
            mat[i][root->data] = 1;
    }
    func(root->left, root->data);
    func(root->right, root->data);
}
int main()
{
}