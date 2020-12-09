/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution
{
public:
    /**
     * @param root: the given tree
     * @return: the number of uni-value subtrees.
     */
    int ans;
    int func(TreeNode *root)
    {
        if (!root->left && !root->right)
        {
            ans++;
            return root->val;
        }
        int l = root->val;
        int r = root->val;
        if (root->left)
            l = func(root->left);
        if (root->right)
            r = func(root->right);
        if (l == r && r == root->val)
        {
            ans++;
            return r;
        }
        return INT_MAX;
    }
    int countUnivalSubtrees(TreeNode *root)
    {
        ans = 0;
        if (!root)
            return 0;
        int k = func(root);
        return ans;
    }
};