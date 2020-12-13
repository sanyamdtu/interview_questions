
// } Driver Code Ends

/* Returns true if the given tree is foldable */

/* A binary tree node has data, pointer to left child
and a pointer to right child */
/*struct node
{
    int data;
    struct node* left;
    struct node* right;
    
    node(int x){
        data = x;
        left = right = NULL;
    }
};
*/
bool f(Node *a, Node *b)
{
    if (a == NULL && b == NULL)
        return true;
    if (a == NULL || b == NULL)
    {

        return false;
    }
    return f(a->left, b->right) & f(a->right, b->left);
}
bool IsFoldable(Node *root)
{
    if (!root)
        return true;
    return f(root->left, root->right);
}

// { Driver Code Starts.
