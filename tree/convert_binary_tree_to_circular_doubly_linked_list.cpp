/*struct Node
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
*/
Node *add(Node *p, Node *q)
{
    if (!p)
        return q;
    else if (!q)
        return p;
    else
    {
        Node *a = p->right;
        Node *b = q->right;
        p->right = b;
        b->left = p;
        a->left = q;
        q->right = a;
        return q;
    }
}
Node *func(Node *root)
{
    if (!root)
        return NULL;
    Node *l = NULL, *r = NULL;
    l = func(root->left);
    r = func(root->right);
    root->left = root->right = root;
    Node *p = add(l, root);
    return add(p, r);
}
Node *bTreeToCList(Node *root)
{
    return func(root)->right;
}