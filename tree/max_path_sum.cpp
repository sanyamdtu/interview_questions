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
class Solution {
public:
    int ans;
    int func(TreeNode * root){
        if(!root)
            return 0;
        int l=func(root->left);
        int r=func(root->right);
        int a=root->val;
        ans=max(ans,max(l+a,max(r+a,max(a,l+r+a))));
        return max(l+a,max(r+a,a));
    }
    int maxPathSum(TreeNode* root) {
        ans=INT_MIN;
        int s=func(root);
        return ans;
    }
};