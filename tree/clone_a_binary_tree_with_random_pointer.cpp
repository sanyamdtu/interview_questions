/* A binary tree node has data, pointer to left child
   and a pointer to right child 
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node *random;
};
*/

/* The function should clone the passed tree and return 
   root of the cloned tree */
Node *clone(Node *&root)
{
    if (!root)
        return NULL;
    Node *nroot = new Node(root->data);
    nroot->left = clone(root->left);
    root->right = clone(root->right);
    root->left = nroot;
    return root;
}
void preorder(Node *&root)
{
    if (!root)
        return;
    if (root->random)
    {
        root->left->random = root->random->left;
    }
    preorder(root->left->left);
    preorder(root->right);
}
Node *func(Node *&root)
{
    if (!root)
        return NULL;
    Node *nroot = root->left;
    root->left = root->left->left;
    nroot->left = func(root->left);
    nroot->right = func(root->right);
    return nroot;
}
Node *cloneTree(Node *root)
{
    if (!root)
        return NULL;
    Node *temp = clone(root);
    preorder(temp);
    return func(temp);
}
