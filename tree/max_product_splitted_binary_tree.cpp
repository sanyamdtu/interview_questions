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
    long long ans;
    long long a;
    long long mod;
    long long sum;
    long long f(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        return (root->val + func(root->left) + func(root->right));
    }
    long long func(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        long long l = func(root->left);
        long long k = (l * (sum - l)) % mod;
        ans = max(ans, k);
        long long r = func(root->right);
        k = (r * (sum - r)) % mod;
        ans = max(ans, k);
        return l + r + root->val;
    }
    int maxProduct(TreeNode *root)
    {
        ans = -1;
        a = 0;
        mod = 1000 * 1000 * 1000;
        mod += 7;
        sum = f(root);
        cout << sum << " " << sum;
        sum = func(root);
        return ans;
    }
};