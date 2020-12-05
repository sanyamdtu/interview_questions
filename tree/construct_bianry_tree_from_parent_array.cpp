struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};
* /

    /*  Function which returns the  root of 
    the constructed binary tree. */
    Node *func(vector<vector<int>> &m, int p)
{
    Node *a = new Node(p);
    if (m[p].empty())
        return a;
    if (m[p].size() >= 1)
        a->left = func(m, m[p][0]);
    if (m[p].size() == 2)
    {
        a->right = func(m, m[p][1]);
    }
    return a;
}
Node *createTree(int p[], int n)
{
    if (n == 0)
        return NULL;
    vector<vector<int>> v(n);
    int a = 0;
    for (int i = 0; i < n; i++)
        if (p[i] != -1)
            v[p[i]].push_back(i);
        else
            a = i;
    return func(v, a);
}