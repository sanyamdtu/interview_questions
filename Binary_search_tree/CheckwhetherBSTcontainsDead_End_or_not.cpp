
/*The Node structure is
struct Node {
int data;
Node * right, * left;
};*/

/*You are required to complete below method */
bool func(Node *root, int l, int r)
{
    if (!root)
        return false;
    if (l == r)
        return true;
    int d = root->data;
    return func(root->left, l, d - 1) | func(root->right, d + 1, r);
}
bool isDeadEnd(Node *root)
{
    return func(root, 1, INT_MAX);
}