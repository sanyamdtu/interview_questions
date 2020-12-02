
/*   
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */
vector<int> reverseLevelOrder(Node *root)
{
    queue<Node *> q;
    vector<int> v;
    q.push(root);
    while (!q.empty())
    {
        auto a = q.front();
        q.pop();
        v.push_back(a->data);
        if (a->right)
            q.push(a->right);
        if (a->left)
            q.push(a->left);
    }
    reverse(v.begin(), v.end());
    return v;
}