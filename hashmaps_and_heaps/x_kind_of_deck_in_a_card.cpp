class Solution
{
public:
    int gcd(int a, int b)
    {

        if (a % b == 0)
            return b;
        return gcd(b, a % b);
    }
    bool hasGroupsSizeX(vector<int> &arr)
    {
        unordered_map<int, int> m;
        for (auto i : arr)
        {
            m[i]++;
        }
        int k = -1;
        for (auto i : m)
        {

            if (k == -1)
                k = i.second;
            else
            {
                k = gcd(k, i.second);
            }
        }
        return (k >= 2 && arr.size() >= 2);
    }
};