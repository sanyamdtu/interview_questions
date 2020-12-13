
//User function Template for C++
/*
Structure of the Node of the node of the bst 
should be as
struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};
*/
// You are required to complete this function
struct a
{
    int l, r;
    Node *p;
    int f;
};
Node *constructBst(int arr[], int n)
{
    queue<a> q;
    if (n == 0)
        return NULL;
    Node *a = new Node(arr[0]);
    q.push({INT_MIN, arr[0] - 1, a, 0});
    q.push({arr[0] + 1, INT_MAX, a, 1});
    int i = 1;
    while (i < n)
    {
        auto p = q.front();
        q.pop();
        if (p.l <= arr[i] && p.r >= arr[i])
        {
            if (p.f == 0)
            {
                p.p->left = new Node(arr[i]);
                q.push({p.l, arr[i] - 1, p.p->left, 0});
                q.push({arr[i] + 1, p.r, p.p->left, 1});
            }
            else
            {
                p.p->right = new Node(arr[i]);
                q.push({p.l, arr[i] - 1, p.p->right, 0});
                q.push({arr[i] + 1, p.r, p.p->right, 1});
            }
            i++;
        }
    }
    return a;
}
