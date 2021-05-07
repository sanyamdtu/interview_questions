int countRev(string a)
{
    int i = 0, n = a.length();
    stack<char> s;
    while (i < n)
    {
        if (!s.empty())
        {
            if (a[i] == '}')
            {
                if (s.top() == '{')
                    s.pop();
                else
                    s.push(a[i]);
            }
            else
                s.push(a[i]);
        }
        else
            s.push(a[i]);
        i++;
    }
    int c = 0, d = 0;
    while (!s.empty())
    {
        // cout<<s.top();
        if (s.top() == '{')
            c++;
        else
            d++;
        s.pop();
    }
    if ((c + d) % 2 != 0)
        return -1;
    int ans = (c) / 2;
    ans += (d) / 2;
    if (c % 2 != 0)
    {
        ans += 2;
    }
    return ans;
}