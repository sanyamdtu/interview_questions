
/*The Node structure is

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// Return the minimum absolute difference between any tree node and the integer K
int minDiff(Node *root, int k)
{
    if (!root)
        return -1;
    int ans = INT_MAX;
    Node *curr = root;
    while (curr)
    {
        ans = min(abs(curr->data - k), ans);
        if (curr->data < k)
        {
            curr = curr->right;
        }
        else
            curr = curr->left;
    }
    return ans;
}
