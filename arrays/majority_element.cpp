class Solution
{
public:
    int majorityElement(vector<int> &arr)
    {
        int val = arr[0], count = 1, n = arr.size();
        for (int i = 1; i < n; i++)
        {
            if (val == arr[i])
                count++;
            else if (count == 0)
            {
                val = arr[i];
                count++;
            }
            else
                count--;
        }
        return val;
    }
};