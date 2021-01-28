#include <bits/stdc++.h>
using namespace std;
int minheap()
{
    return min_heap.top()->data;
}
int maxheap()
{
    return max_heap.top()->data;
}
void deletemin()
{
    
}
int main()
{
    while (1)
    {
        cout << "1 minheap()" << endl;
        cout << "2 maxheap()" << endl;
        cout << "3 delete min()" << endl;
        cout << "4 delete max()" << endl;
        cout << "5 del (val)" << endl;
        cout << "6 insert(val)" << endl;
        cout << "7 break()" << endl;
    }
}