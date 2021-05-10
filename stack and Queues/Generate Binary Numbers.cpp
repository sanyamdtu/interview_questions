//Function to generate binary numbers from 1 to N using a queue.
struct node
{
    int num;
    string s;
};
vector<string> generate(int n)
{
    vector<string> ans;
    queue<node> q;
    q.push({1, "1"});
    while (!q.empty())
    {
        auto a = q.front();
        q.pop();
        ans.push_back(a.s);
        int p = a.num * 2;
        if (p <= n)
            q.push({p, a.s + "0"});
        if (p + 1 <= n)
            q.push({p + 1, a.s + "1"});
    }
    return ans;
}
