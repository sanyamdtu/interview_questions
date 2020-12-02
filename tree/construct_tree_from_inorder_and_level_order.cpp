
/*Complete the function below
Node is as follows:
struct Node
{
    int key;
    struct Node* left, *right;
};
*/
unordered_map<int, int> m;
Node *func(int si, int ei, int cnt, int in[], int l[])
{
    if (si > ei || cnt <= 0)
        return NULL;
    int r = l[0];
    Node *root = new Node(r);
    int idx = m[r];
    int lcnt = idx - si;
    int rcnt = ei - idx;
    int llevel[lcnt];
    int rlevel[rcnt];
    int j = 0, k = 0;
    unordered_map<int, int> p;
    for (int i = 0; i < cnt; i++)
    {
        if (m[l[i]] < idx)
        {
            llevel[j++] = l[i];
        }
        else if (m[l[i]] > idx)
        {
            rlevel[k++] = l[i];
        }
    }
    root->left = func(si, idx - 1, lcnt, in, llevel);
    root->right = func(idx + 1, ei, rcnt, in, rlevel);
    return root;
}
Node *buildTree(int in[], int l[], int is, int ie, int n)
{
    m.clear();
    for (int i = 0; i < n; i++)
        m[in[i]] = i;
    return func(0, n - 1, n, in, l);
}