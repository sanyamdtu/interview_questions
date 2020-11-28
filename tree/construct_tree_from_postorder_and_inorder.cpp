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
    vector<int> in, po;
    unordered_map<int, int> m;
    TreeNode *func(int si, int ei, int ps, int pe)
    {
        if (ps > pe || si > ei)
            return NULL;
        int r = po[pe];
        int idx = m[r];
        int cnt = idx - si;
        TreeNode *root = new TreeNode(r);
        root->left = func(si, idx - 1, ps, ps + cnt - 1);
        root->right = func(idx + 1, ei, ps + cnt, pe - 1);
        return root;
    }
    TreeNode *buildTree(vector<int> &in, vector<int> &po)
    {
        this->in = in;
        this->po = po;
        m.clear();
        for (int i = 0; i < in.size(); i++)
            m[in[i]] = i;
        return func(0, in.size() - 1, 0, po.size() - 1);
    }
};