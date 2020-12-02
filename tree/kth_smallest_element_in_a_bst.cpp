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
    int kthSmallest(TreeNode *root, int k)
    {
        TreeNode *curr = root;
        vector<int> v;
        while (curr)
        {
            // cout<<curr->val<<" ";
            if (curr->left == NULL)
            {
                v.push_back(curr->val);
                curr = curr->right;
            }
            else
            {
                TreeNode *temp = curr->left;
                while (temp->right != NULL && temp->right != curr)
                {
                    temp = temp->right;
                }
                if (temp->right == NULL)
                {
                    temp->right = curr;
                    if (curr)
                        curr = curr->left;
                }
                else
                {
                    v.push_back(curr->val);
                    temp->right = NULL;
                    if (curr)
                        curr = curr->right;
                }
            }
        }
        return v[k - 1];
    }
};