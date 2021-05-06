class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &arr)
    {
        vector<int> ans;
        int n = arr.size(), i = 0;
        stack<int> s;
        while (i < n)
        {
            int a = arr[i];
            while (!s.empty() && a < 0 && s.top() > 0)
            {
                int b = s.top();
                s.pop();
                if (abs(b) == abs(arr[i]))
                {
                    a = 0;
                    break;
                }
                else if (abs(b) > abs(arr[i]))
                    a = b;
                else
                    a = arr[i];
            }
            if (a != 0)
                s.push(a);
            i++;
        }
        while (!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};