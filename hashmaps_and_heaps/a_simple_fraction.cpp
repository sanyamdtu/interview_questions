
class Solution
{
public:
    string fractionToDecimal(int d, int n)
    {
        string first = "", second = "";
        first = to_string(d / n);
        d = d % n;
        if (d == 0)
            return first;
        first += '.';
        unordered_map<int, int> m;
        int i = 1;
        while (d != 0)
        {
            if (m[d] != 0)
            {
                for (int i = 0; i < second.length(); i++)
                {
                    if (m[d] == i + 1)
                        first += '(';
                    first += second[i];
                }
                first += ')';
                return first;
            }
            m[d] = i;
            i++;
            d = d * 10;
            second += to_string(d / n);
            d %= n;
        }
        return first + second;
    }
};
