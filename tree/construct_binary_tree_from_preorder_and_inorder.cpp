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
    vector<int> p;
    vector<int> i;
    unordered_map<int, int> m;
    TreeNode *func(int si, int ei, int sp, int ep)
    {
        if (si > ei || sp > ep)
            return NULL;
        int r = p[sp];
        TreeNode *root = new TreeNode(r);
        int idx = m[r];
        int cnt = idx - si;
        root->left = func(si, idx - 1, sp + 1, cnt + sp);
        root->right = func(idx + 1, ei, cnt + sp + 1, ep);
        return root;
    }
    TreeNode *buildTree(vector<int> &pre, vector<int> &in)
    {
        p = pre;
        i = in;
        m.clear();
        for (int i = 0; i < in.size(); i++)
            m[in[i]] = i;
        return func(0, in.size() - 1, 0, pre.size() - 1);
    }
};