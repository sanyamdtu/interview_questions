class Solution
{
public:
    int dominantIndex(vector<int> &arr)
    {
        if (arr.size() == 1)
            return 0;
        int a, b;
        b = a = -1;
        for (int i = 0; i < arr.size(); i++)
        {
            if (i == 0 || arr[a] < arr[i])
            {
                swap(a, b);
                a = i;
            }
            else if (b == -1 || arr[b] < arr[i])
                b = i;
        }
        int f = -1;
        // cout<<a<<" "<<b;
        if (arr[a] >= 2 * arr[b])
            f = a;
        return f;
    }
};