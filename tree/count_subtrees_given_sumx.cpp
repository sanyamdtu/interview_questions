/*
Structure of the node of the binary tree is as struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
*/
// your are required to complete this function
// function should return the count of the number of
// subtrees with Sum equal to X
int sum,
    ans;

int func(Node *root)
{
    if (!root)
    {
        return 0;
    }
    int l = func(root->left);
    int r = func(root->right);
    int t = l + r + root->data;
    if (t == sum)
        ans++;
    return t;
}
int countSubtreesWithSumX(Node *root, int X)
{
    sum = X;
    ans = 0;
    int a = func(root);
    return ans;
}
