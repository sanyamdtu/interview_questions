bool areKAnagrams(string s, string t, int k)
{
    if (s.length() != t.length())
        return false;
    unordered_map<char, int> m, p;
    for (auto i : s)
        m[i]++;
    for (auto i : t)
        p[i]++;
    int c = 0;
    for (auto i : m)
        if (i.second > p[i.first])
            c += i.second - p[i.first];
    return c <= k;
}