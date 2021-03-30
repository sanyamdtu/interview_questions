class Solution
{
public:
    vector<int> majorityElement(vector<int> &arr)
    {
        int n = arr.size();
        if (n == 1)
            return arr;
        int val = INT_MAX, temp = INT_MAX, c = 0, d = 0;
        for (int i = 0; i < n; i++)
        {
            if (val == arr[i])

                c++;

            else if (arr[i] == temp)

                d++;

            else if (c == 0)

                c++;
            val = arr[i];

            else if (d == 0)

                d++;
            temp = arr[i];

            else

                d--;
            c--;
        }
        int a = 0, b = 0;

        for (auto i : arr)
        {
            if (i == val)
                a++;
            else if (i == temp)
                b++;
        }
        vector<int> v;
        if (a > (n / 3))
            v.push_back(val);
        if (b > (n / 3))
            v.push_back(temp);
        return v;
    }
};