class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &arr)
    {
        int p[26];
        unordered_map<string, vector<int>> m;
        for (int i = 0; i < arr.size(); i++)
        {
            memset(p, 0, sizeof(p));
            for (auto j : arr[i])
                p[j - 'a']++;
            string a = "";
            for (int j = 0; j < 26; j++)
                a += to_string(p[j]) + "^^";
            m[a].push_back(i);
        }
        vector<vector<string>> ans;
        for (auto i : m)
        {
            vector<string> a;
            for (auto j : i.second)
                a.push_back(arr[j]);
            ans.push_back(a);
        }
        return ans;
    }
};