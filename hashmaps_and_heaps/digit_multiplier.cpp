
class Solution
{
public:
    string getSmallest(long long n)
    {

        map<long long, int> m;
        string ans = "";
        if (n < 10)
            return to_string(n);
        long long i = 9;
        while (i >= 2 && n > 1)
        {
            if ((n % i) == 0)
            {
                m[i]++;
                n /= i;
            }
            else
                i--;
        }
        if (n != 1)
            return "-1";
        for (auto i : m)
        {
            int a = i.second;
            while (a--)
                ans += '0' + i.first;
        }
        return ans;
    }
};
