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
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> v;
        queue<TreeNode*> q;      
        if(root!=NULL)
            q.push(root);
        while(!q.empty()){
            int size=q.size();
            while(size>0){
                TreeNode* a=q.front();
                q.pop();
                if(a->right)
                    q.push(a->right);
                if(a->left)
                    q.push(a->left);
                
                if(size==1)
                    v.push_back(a->val);
                size--;
            }
        }
        return v;
    }
};