
/*Complete the function below
Node is as follows:
struct Node{
    int data;
    Node *left,*right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
// return the head of the DLL and remove those node from the tree as well.
Node *a, *b;
Node *func(Node *root)
{
    if (!root->left && !root->right)
    {
        if (!a)
        {
            a = root;
            b = root;
        }
        else
        {
            a->right = root;
            root->left = a;
            a = root;
        }
        return NULL;
    }
    if (root->left)
        root->left = func(root->left);
    if (root->right)
        root->right = func(root->right);
    return root;
}
Node *convertToDLL(Node *root)
{
    if (!root)
        return NULL;
    a = NULL, b = NULL;
    Node *temp = func(root);
    return b;
}
