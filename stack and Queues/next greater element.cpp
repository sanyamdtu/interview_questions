

class Solution
{
public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n)
    {
        stack<int> s;
        vector<long long> ans(n);
        int i = 0;
        while (i < n)
        {
            while (!s.empty() && arr[i] > arr[s.top()])
            {
                ans[s.top()] = arr[i];
                s.pop();
            }
            s.push(i);
            i++;
        }
        while (!s.empty())
        {
            ans[s.top()] = -1;
            s.pop();
        }
        return ans;
    }
};
