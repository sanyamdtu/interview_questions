#define mod 1000000007

int fun(string &s)
{
    long long n = s.length(), a, b, c;
    a = b = c = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'a')
        {
            a = (1 + a + a) % mod;
        }
        else if (s[i] == 'b')
        {
            b = (b + a + b) % mod;
        }
        else
        {
            c = (b + c + c) % mod;
        }
    }
    return c;
}
