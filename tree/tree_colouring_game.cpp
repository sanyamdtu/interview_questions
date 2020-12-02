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
    TreeNode *func(TreeNode *root,int key){
        if(root==NULL)
            return NULL;
        if(root->val>key)
            return func(root->left,key);
        else if(root->val<key)
            return func(root->right,key);
        else
            return root;
    }
    int f(TreeNode* root,int x){
        if(!root)
            return 0;
        if(root->val==x)
            return 0;
        return f(root->left,x)+f(root->right,x)+1;
    }
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        TreeNode * temp=func(root,x);
        // cout<<temp->val;
        int c=0;
        
        if(temp)
        c=f(temp->left,x);
        c=max(f(root,x),c);
        if(temp)
        c=max(c,f(temp->right,x));
        cout<<c;
        return (c>n-c);
    }
};