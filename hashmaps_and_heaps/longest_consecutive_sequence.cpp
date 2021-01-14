typedef long long ll;
class Solution
{
public:
    int longestConsecutive(vector<int> &arr)
    {
        unordered_map<ll, ll> m;
        for (auto i : arr)
        {
            if (m.find(i) != m.end())
                continue;
            m[i]++;
            if (m.find(i - 1) != m.end() && m.find(i + 1) != m.end())
            {

                ll s = i - m[i - 1];
                ll e = i + m[i + 1];
                m[e] = e - s + 1;
                m[s] = e - s + 1;
            }
            else if (m.find(i - 1) == m.end() && m.find(i + 1) != m.end())
            {
                ll e = i + m[i + 1];
                m[e] = e - i + 1;
                m[i] = e - i + 1;
            }
            else if (m.find(i - 1) != m.end() && m.find(i + 1) == m.end())
            {

                ll s = i - m[i - 1];
                m[i] = i - s + 1;
                m[s] = i - s + 1;
            }
        }
        ll ans = 0;
        for (auto i : m)
            ans = max(ans, i.second);
        return ans;
    }
};