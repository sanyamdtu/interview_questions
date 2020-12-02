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
    int key;
    TreeNode * del(TreeNode * root){
        if(!root->left&&!root->right)
            return NULL;
        else if(!root->left){
            return root->right;
        }
        else if(!root->right){
            return root->left;
        }
        else{
            TreeNode * temp=root->right;
            while(temp->left!=NULL){
                temp=temp->left;
            }
            temp->left=root->left;
            root=root->right;
            return root;
        }
    }
    TreeNode * func(TreeNode *root){
        if(root==NULL){
            return root;
        } 
        if(root->val>key){
            root->left=func(root->left);
            return root;
        }
        else if(root->val<key){
            root->right=func(root->right);
            return root;
        }
        else{
            return del(root);
        }
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        this->key=key;
        return func(root);
    }
};