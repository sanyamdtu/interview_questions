/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
public:
    TreeNode *func(TreeNode *root, int p, int q)
    {
        if (!root)
            return NULL;
        if (root->val > p && root->val > q)
            return func(root->left, p, q);
        else if (root->val < p && root->val < q)
            return func(root->right, p, q);
        else
            return root;
    }
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        return func(root, p->val, q->val);
    }
};