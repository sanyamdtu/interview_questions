
/* Tree node structure  used in the program

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

/* Computes the diameter of binary tree with given root.  */
pair<int, int> func(Node *root)
{
    if (!root->left && !root->right)
    {
        return {1, 1};
    }
    else if (root->left && root->right)
    {
        auto l = func(root->left);
        auto r = func(root->right);
        return {max(l.first, r.first) + 1, max(l.first + 1 + r.first, max(l.second, r.second))};
    }
    else if (root->right)
    {
        auto r = func(root->right);
        return {r.first + 1, r.second};
    }
    else
    {
        auto l = func(root->left);
        return {l.first + 1, l.second};
    }
}
int diameter(Node *root)
{
    if (!root)
        return 0;
    auto a = func(root);
    return max(a.first, a.second);
}
