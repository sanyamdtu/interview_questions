using namespace std;

static constexpr int kMod = 1000000007;

struct Node
{
public:
    const long long v;
    Node *le;
    Node *ri;

    Node(long long v) : v(v), le(nullptr), ri(nullptr) {}
};

Node *getNode(unordered_map<int, Node *> &map, int v)
{
    const auto &it = map.find(v);
    if (it != map.end())
    {
        return it->second;
    }

    Node *node = new Node(v);
    map.insert({v, node});
    return node;
}

Node *readNode(unordered_map<int, Node *> &map)
{
    int v;
    cin >> v;
    return getNode(map, v);
}

void readChildNode(Node *parent, unordered_map<int, Node *> &map)
{
    auto *node = readNode(map);

    char let;
    cin >> let;
    if (let == 'L')
    {
        parent->le = node;
    }
    else
    {
        parent->ri = node;
    }
}

void readNodes(unordered_map<int, Node *> &map)
{
    auto *parent = readNode(map);
    readChildNode(parent, map);
}

long long dfs(Node *n1, Node *n2)
{
    if (n1 == nullptr || n2 == nullptr)
    {
        return 0;
    }
    long long v = n1->v;
    v *= n2->v;
    return (v + dfs(n1->le, n2->ri) + dfs(n1->ri, n2->le)) % kMod;
}

long long mult(Node *root)
{
    long long v = root->v;
    return (v * v + dfs(root->le, root->ri)) % kMod;
}

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n;
        cin >> n;

        unordered_map<int, Node *> nodes;

        Node *root = readNode(nodes);
        readChildNode(root, nodes);
        for (int i = 1; i < n; i++)
        {
            readNodes(nodes);
        }

        cout << mult(root) << '\n';
    }
    return 0;
}
