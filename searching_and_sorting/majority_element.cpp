class Solution
{
public:
    int majorityElement(vector<int> &arr)
    {
        int n = arr.size();
        int m = 0, c = 1;
        for (int i = 1; i < n; i++)
        {
            if (arr[i] == arr[m])
                c++;
            else
                c--;
            if (c == 0)
            {
                m = i;
                c = 1;
            }
        }
        return arr[m];
    }
};