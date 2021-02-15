#include <bits/stdc++.h>
using namespace std;

struct node
{
    int num;
    char ch;
    node *left, *right;
};
struct comp
{
    bool operator()(node *a, node *b)
    {
        return a->num > b->num;
    }
};
void dfs(node *root, string p, unordered_map<char, string> &m)
{
    if (!root->left && !root->right)
    {
        m[root->ch] = p;
    }
    else if (!root->left)
    {
        dfs(root->right, p + '1', m);
    }
    else if (!root->right)
    {
        dfs(root->left, p + '0', m);
    }
    else
    {
        dfs(root->left, p + '0', m);
        dfs(root->right, p + '1', m);
    }
}
int main()
{
    string s;
    cin >> s;
    int n = s.length();
    unordered_map<char, int> m;
    for (int i = 0; i < n; i++)
    {
        m[s[i]]++;
    }
    priority_queue<node *, vector<node *>, comp> q;
    for (auto i : m)
    {
        node *temp = new node;
        temp->ch = i.first;
        temp->num = i.second;
        q.push(temp);
    }
    while (q.size() != 1)
    {
        auto a = q.top();
        q.pop();
        auto b = q.top();
        q.pop();
        node *temp = new node;
        temp->num = a->num + b->num;
        temp->left = a;
        temp->right = b;
        q.push(temp);
    }
    unordered_map<char, string> w;
    dfs(q.top(), "", w);
    string ans = "";
    for (auto i : s)
    {
        ans += w[i];
    }
    unordered_map<string, char> u;
    for (auto i : w)
    {
        u[i.second] = i.first;
    }
    cout << ans << endl;
    string a, b = "";
    cin >> a;
    ans = "";
    for (auto i : a)
    {
        b += i;
        if (u.find(b) != u.end())
        {
            ans += u[b];
            b = "";
        }
    }
    cout << ans;
}