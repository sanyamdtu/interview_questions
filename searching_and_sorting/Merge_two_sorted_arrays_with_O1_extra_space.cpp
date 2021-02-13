// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

void merge(int a[], int b[], int n, int m)
{
    int i = 0;
    if (m == 0)
        return;
    while (i < n)
    {
        if (a[i] > b[0])
        {

            swap(a[i], b[0]);
            i++;
            for (int k = 0; k < m - 1; k++)
            {
                if (b[k] > b[k + 1])
                    swap(b[k], b[k + 1]);
            }
        }
        else
            i++;
    }
}

// { Driver Code Starts.

int main()
{

    int T;
    cin >> T;

    while (T--)
    {
        int n, m;
        cin >> n >> m;

        int arr1[n], arr2[m];

        for (int i = 0; i < n; i++)
        {
            cin >> arr1[i];
        }

        for (int i = 0; i < m; i++)
        {
            cin >> arr2[i];
        }

        merge(arr1, arr2, n, m);

        for (int i = 0; i < n; i++)
            printf("%d ", arr1[i]);

        for (int i = 0; i < m; i++)
            printf("%d ", arr2[i]);

        cout << endl;
    }

    return 0;
}
// } Driver Code Ends