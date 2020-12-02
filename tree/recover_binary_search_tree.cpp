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
    int f;
    TreeNode *q = NULL;
    void func(TreeNode *&prev, TreeNode *&p, TreeNode *&curr)
    {

        if (prev)
        {
            if (p)
            {
                if (prev->val > curr->val)
                {
                    f = 1;
                    swap(p->val, curr->val);
                }
            }
            else if (prev->val > curr->val)
            {
                p = prev;
                q = curr;
            }
        }
        prev = curr;
    }
    void recoverTree(TreeNode *&root)
    {
        f = 0;
        TreeNode *curr = root;
        TreeNode *prev = NULL, *p = NULL;
        while (curr)
        {
            if (curr->left == NULL)
            {
                func(prev, p, curr);
                curr = curr->right;
            }
            else
            {
                TreeNode *temp = curr->left;
                while (temp->right && temp->right != curr)
                {
                    temp = temp->right;
                }
                if (!temp->right)
                {
                    temp->right = curr;
                    curr = curr->left;
                }
                else
                {
                    func(prev, p, curr);
                    temp->right = NULL;
                    curr = curr->right;
                }
            }
        }
        if (f == 0)
        {
            swap(p->val, q->val);
        }
    }
};