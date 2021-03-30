class Solution
{
public:
    int maximumProduct(vector<int> &arr)
    {
        int a, b, c, d, e;
        a = b = c = INT_MIN;
        e = d = INT_MAX;
        for (auto i : arr)
        {
            if (a < i)
            {
                swap(b, c);
                swap(a, b);
                a = i;
            }
            else if (b < i)
            {
                swap(b, c);
                b = i;
            }
            else if (c < i)
                c = i;
            if (d > i)
            {
                swap(e, d);
                d = i;
            }
            else if (e > i)
                e = i;
        }
        return max(a * b * c, a * d * e);
    }
};