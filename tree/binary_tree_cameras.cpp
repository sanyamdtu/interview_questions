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
            return 3;
        int l = func(root->left);
        int r = func(root->right);
        if (l == 1 || r == 1)
        {
            ans++;
            return 2;
        }
        else if (l == 2 || r == 2)
        {
            return 3;
        }
        else
        {
            return 1;
        }
    }
    int minCameraCover(TreeNode *root)
    {
        ans = 0;
        if (func(root) == 1)
            ans++;
        return ans;
    }
};