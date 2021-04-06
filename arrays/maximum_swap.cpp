class Solution
{
public:
    int maximumSwap(int num)
    {
        int arr[10];
        for (int i = 0; i < 10; i++)
            arr[i] = -1;
        string s = to_string(num);

        int n = s.length();
        for (int i = 0; i < n; i++)
            arr[s[i] - '0'] = i;
        for (int j = 0; j < n; j++)
        {
            int i = s[j] - '0';
            int f = 0;
            for (int k = 9; k > i; k--)
            {
                if (arr[k] != -1 && arr[k] > j)
                {
                    swap(s[j], s[arr[k]]);
                    f = 1;
                    break;
                }
            }
            if (f == 1)
                break;
        }
        return stoi(s);
    }
};