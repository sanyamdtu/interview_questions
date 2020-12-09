/**
 * Definition for a binary tree TreeNode.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
public:
    /*
     * @param root: The root of the BST.
     * @param p: You need find the successor TreeNode of p.
     * @return: Successor of p.
     */
    TreeNode *func(TreeNode *root, int key)
    {
        TreeNode *last = NULL;
        if (root->val > key)
            last = root;
        while (root)
        {

            if (root->val > key)
            {
                last = root;
                root = root->left;
            }
            else if (root->val < key)
                root = root->right;

            else
                break;
        }
        return last;
    }
    TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p)
    {
        if (!root || !p)
            return NULL;
        TreeNode *r = p->right;

        if (!r)
            return func(root, p->val);

        while (r->left)
        {
            r = r->left;
        }
        return r;
    }
};