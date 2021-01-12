typedef long long ll;
class Solution
{
public:
    int minRefuelStops(int k, int a, vector<vector<int>> &arr)
    {
        ll i = 0;
        ll n = arr.size();
        multiset<ll, greater<ll>> s;
        ll ans = 0;
        while (i < n)
        {
            while (!s.empty() && a < arr[i][0])
            {
                auto p = *(s.begin());
                s.erase(s.begin());
                a += p;
                ans++;
            }
            if (a < arr[i][0])
                return -1;
            s.insert(arr[i][1]);
            i++;
        }
        while (!s.empty() && a < k)
        {
            auto p = *(s.begin());
            s.erase(s.begin());
            a += p;
            ans++;
        }
        if (a < k)
            return -1;
        return ans;
    }
};