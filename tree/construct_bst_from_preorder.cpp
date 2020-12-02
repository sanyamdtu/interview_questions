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
struct a
{
    int l, r;
    TreeNode *par;
    int flag;
};
class Solution
{
public:
    TreeNode *bstFromPreorder(vector<int> &p)
    {
        if (p.empty())
            return NULL;
        int i = 0;
        TreeNode *root = new TreeNode(p[0]);
        stack<a> s;
        s.push({p[i] + 1, INT_MAX, root, 1});
        s.push({INT_MIN, p[i] - 1, root, 0});
        i++;
        while (!s.empty() && i < p.size())
        {
            auto k = s.top();
            // cout<<k.l<<" "<<k.r<<" "<<k.par->val<<" "<<k.flag<<endl;
            s.pop();
            if (p[i] >= k.l && p[i] <= k.r)
            {
                // cout<<p[i]<<" "<<k.l<<" "<<k.r<<endl;
                TreeNode *node = new TreeNode(p[i]);
                if (k.flag == 0)
                {
                    k.par->left = node;
                    s.push({p[i] + 1, k.r, node, 1});
                    s.push({k.l, p[i] - 1, node, 0});
                }
                else
                {
                    k.par->right = node;
                    s.push({p[i] + 1, k.r, node, 1});
                    s.push({k.l, p[i] - 1, node, 0});
                }
                i++;
            }
        }
        return root;
    }
};