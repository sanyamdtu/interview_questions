/*struct node
{
    int data;
    struct node *left;
    struct node *right;

    node(int x)
    {
        data = x;
        left = right = NULL;
    }
};
*/
node *add(node *p, node *q)
{
    if (!p)
        return q;
    else if (!q)
        return p;
    else
    {
        node *a = p->right;
        node *b = q->right;
        p->right = b;
        b->left = p;
        a->left = q;
        q->right = a;
        return q;
    }
}
node *func(node *root)
{
    if (!root)
        return NULL;
    node *l = NULL, *r = NULL;
    l = func(root->left);
    r = func(root->right);
    root->left = root->right = root;
    node *p = add(l, root);
    return add(p, r);
}
node *bTreeToCList(node *root)
{
    return func(root)->right;
}
node *bToDLL(node *root)
{
    if (!root)
        return NULL;
    node *a = func(root)->right;
    a->left->right = NULL;
    a->left = NULL;
    return a;
}