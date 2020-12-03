/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int ans;
    int func(TreeNode *root)
    {
        if (!root)
            return 0;
        int l = func(root->left);
        int r = func(root->right);
        ans += abs(l + r - 1 + root->val);
        return (l + r - 1 + root->val);
    }
    int distributeCoins(TreeNode *root)
    {
        ans = 0;
        int p = func(root);
        return ans;
    }
};