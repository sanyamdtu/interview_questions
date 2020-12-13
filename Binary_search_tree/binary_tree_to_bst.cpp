
/* The Node structure is
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
}; 
*/

// The given root is the root of the Binary Tree
// Return the root of the generated BST
void func(Node *root, vector<Node *> &v)
{
    if (!root)
        return;
    func(root->left, v);
    v.push_back(root);
    func(root->right, v);
}
Node *binaryTreeToBST(Node *root)
{
    if (!root)
        return root;
    vector<Node *> v;
    func(root, v);
    int n = v.size();
    int arr[n];
    for (int i = 0; i < n; i++)
        arr[i] = v[i]->data;
    sort(arr, arr + n);
    for (int i = 0; i < n; i++)
        v[i]->data = arr[i];

    return root;
}