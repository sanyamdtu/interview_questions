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
    TreeNode *func(TreeNode* &root){
        if(!root)
            return NULL;
        if(!root->left&&!root->right)
            return root;
        else if(!root->right){
            TreeNode * lt=func(root->left);
            TreeNode *lh=root->left;
            root->right=lh;
            root->left=NULL;
            return lt;
        }
        else if(!root->left){
            TreeNode * rt=func(root->right);
            return rt;
        }
        else{
            TreeNode *lt=func(root->left);
            TreeNode *rt=func(root->right);
            lt->right=root->right;
            root->right=root->left;
            root->left=NULL;
            return rt;
        }   
    }
    void flatten(TreeNode* root) {
        TreeNode * f=func(root);
    }
};