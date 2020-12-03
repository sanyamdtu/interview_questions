#include <bits/stdc++.h>
using namespace std;
sturct node
{
    node *next, *prev;
    int data;
}
node *temp;
node *func(int n)
{
    if (n <= 0)
        return NULL;
    node *left = func(n / 2);
    temp->prev = left;
    node *root = temp;
    temp = temp->next;
    root->next = func(n - (n / 2) - 1);
    return root;
}
