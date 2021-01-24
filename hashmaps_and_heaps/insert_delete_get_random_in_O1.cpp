class RandomizedSet
{
public:
    /** Initialize your data structure here. */
    unordered_map<int, int> m;
    vector<int> v;
    RandomizedSet()
    {
        m.clear();
        v.clear();
    }
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val)
    {
        if (m.find(val) != m.end())
            return false;
        m[val] = v.size();
        v.push_back(val);
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val)
    {
        if (m.find(val) == m.end())
            return false;
        m[v.back()] = m[val];
        swap(v[v.size() - 1], v[m[val]]);
        v.pop_back();
        m.erase(m.find(val));
        return true;
    }

    /** Get a random element from the set. */
    int getRandom()
    {
        int num = rand() % (v.size());
        return v[num];
    }
};
