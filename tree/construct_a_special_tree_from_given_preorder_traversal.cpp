#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *right, *left;
};
int i = 0;
int pre[20000];
char arr[20000];
node *func()
{
    node *a = new node;
    a->data = pre[i];
    i++;
    if (arr[i] == 'L')
        return a;
    a->left = func();
    a->right = func();
    return a;
}
int main()
{
}