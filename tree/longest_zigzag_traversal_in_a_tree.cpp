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
    //0 means left and
    //1 means right
    void func(TreeNode *root,int l,int f){
        if(!root)
            return ;
        ans=max(l,ans);        
        if(f==0){
            func(root->right,l+1,1);
            func(root->left,1,0);
        }
        else{
            func(root->left,l+1,0);
            func(root->right,1,1);
        }
    }
    int longestZigZag(TreeNode* root) {
        ans=0;
        if(!root)
            return 0;
        func(root->left,1,0);
        func(root->right,1,1);
        return ans;
    }
};