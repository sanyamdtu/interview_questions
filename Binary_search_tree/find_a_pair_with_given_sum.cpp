
/*Complete the function below
Node is as follows
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// root : the root Node of the given BST
// target : the target sum
Node *merge(Node *p, Node *q)
{
    if (!p)
        return q;
    if (!q)
        return p;
    Node *a = p->right;
    Node *b = q->right;
    a->left = q;
    q->right = a;
    b->left = p;
    p->right = b;
    return q;
}
Node *func(Node *root)
{
    if (!root)
        return NULL;
    Node *l, *r;
    l = func(root->left);
    r = func(root->right);
    root->left = root->right = root;
    Node *a = merge(l, root);
    return merge(a, r);
    return root;
}
int isPairPresent(struct Node *root, int k)
{
    if (!root)
        return 0;
    Node *a = func(root)->right;
    Node *b = a->left;
    b->right = NULL;
    a->left = NULL;
    int ans = 0;
    // while()
    while (a != b)
    {
        // cout<<a->data<<" "<<b->data<<endl;
        int sum = a->data + b->data;
        if (sum == k)
        {
            return 1;
        }
        else if (sum > k)
        {
            b = b->left;
        }
        else
            a = a->right;
    }
    return 0;
}