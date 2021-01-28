#include <bits/stdc++.h>
using namespace std;
class heap
{
public:
    int size, arr[1000];
    heap()
    {
        size = 0;
    }
    void push(int val)
    {
        arr[size + 1] = val;
        size++;
        int i = size;
        while (i != 1 && arr[i] < arr[i / 2])
        {
            swap(arr[i], arr[i / 2]);
            i /= 2;
        }
    }
    int pop()
    {
        if (size == 0)
            return -1;
        int a = arr[1], i = 1;
        swap(arr[1], arr[size]);
        size--;
        while (1)
        {
            int l = 2 * i;
            int r = 2 * i + 1;
            if (l <= size && r <= size && arr[i] > min(arr[l], arr[r]))
            {
                if (arr[l] < arr[r])
                {
                    swap(arr[l], arr[i]);
                    i = l;
                }
                else
                {
                    swap(arr[r], arr[i]);
                    i = r;
                }
            }
            else if (l <= size && r > size && arr[i] > arr[l])
            {
                swap(arr[l], arr[i]);
                i = l;
            }
            else if (l > size && r <= size && arr[i] > arr[r])
            {
                swap(arr[r], arr[i]);
                i = r;
            }
            else
                break;
        }
        return a;
    }
    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    int n;
    cin >> n;
    heap pq;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        pq.push(a);
        pq.print();
    }
    while (pq.size != 0)
    {
        cout << pq.pop() << "->";
        pq.print();
    }
}