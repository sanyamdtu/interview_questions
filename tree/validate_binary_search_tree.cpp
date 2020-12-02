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
    bool func(TreeNode *root,long long l,long long r){
        if(!root)
            return true;
        if(root->val<l||root->val>r){
            return false;
        }   
        return func(root->left,l,(long)root->val-1)&func(root->right,(long)root->val+1,r);
    }
    bool isValidBST(TreeNode* root) {
        return func(root,-10000000000,10000000000);
    }
};