class MedianFinder
{
public:
    priority_queue<int> a, b;
    MedianFinder()
    {
        a = priority_queue<int>();
        b = priority_queue<int>();
    }
    void addNum(int num)
    {
        if (a.size() == b.size())
        {
            a.push(num);
            int v = a.top();
            a.pop();
            b.push(-v);
        }
        else
        {
            b.push(-num);
            int v = -b.top();
            b.pop();
            a.push(v);
        }
    }

    double findMedian()
    {
        if (a.size() == b.size())
            return (a.top() * 1.0 - b.top() * 1.0) / 2;
        return -b.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */