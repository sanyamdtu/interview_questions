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
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        vector<vector<int>> v;
        map<int, vector<int>> m;
        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});
        while (!q.empty())
        {
            int size = q.size();
            map<int, vector<int>> s;
            while (size > 0)
            {
                auto a = q.front();
                q.pop();
                if (a.first->right)
                    q.push({a.first->right, a.second + 1});
                if (a.first->left)
                    q.push({a.first->left, a.second - 1});
                s[a.second].push_back(a.first->val);
                size--;
            }
            for (auto i : s)
            {
                sort(i.second.begin(), i.second.end());
                for (auto j : i.second)
                {
                    m[i.first].push_back(j);
                }
            }
        }
        for (auto i : m)
        {
            v.push_back(i.second);
        }
        return v;
    }
};