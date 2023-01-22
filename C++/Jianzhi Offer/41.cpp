/*
    最大堆+最小堆，
    addNum(), T=O(logn)
    findMedian(), T=O(1)
*/

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
    }
    priority_queue<int, vector<int>, less<int> > max_q; // 最大堆记录数据流中的较小的一半数据
    priority_queue<int, vector<int>, greater<int> > min_q; // 最大堆记录数据流中的较大的一半数据
    
    void addNum(int num) { // 更新堆的操作，时间复杂度为O(logn)，我们应尽量保证两个堆的元素均衡，以便findMedian()能以O(1)的效率应答
        // 两个堆中数据相同时，优先放入到最小堆中
        // 注意是将num放入最大堆中之后，再将更新后的最大堆中的最大值放入最小堆
        if (max_q.size() == min_q.size()) 
        {
            max_q.push(num);
            min_q.push(max_q.top());
            max_q.pop();
        }
        // 两个堆中数据不相同时，由上面可知，最小堆中的元素一定比最大堆中的元素多一个，所以此时要给最大堆补充元素
        // 但要注意的是，是将num放入最小堆中之后，再将更新后的最小堆中的最小值放入最大堆
        else
        {
            min_q.push(num);
            max_q.push(min_q.top());
            min_q.pop();
        }
    }
    
    double findMedian() {
        if (max_q.size() != min_q.size()) return min_q.top();
        else return (max_q.top() + min_q.top()) / 2.0;
    }
};


/*
    这里列出我一开始的做法，虽然整体思路是对的，但是时间效率相比慢了不少
*/
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        cnt = 0;
    }
    int cnt;
    priority_queue<int, vector<int>, less<int> > max_q;
    priority_queue<int, vector<int>, greater<int> > min_q;
    
    void addNum(int num) { // 更新堆时，我考虑应放入那个堆，所以逻辑判断很多，同时也没有保证两个堆的大小均衡，T=O(log)
        cnt++;
        if (max_q.empty() && min_q.empty()) max_q.push(num);
        else if (!max_q.empty() && num <= max_q.top()) max_q.push(num);
        else if (min_q.empty()) min_q.push(num);
        else if (!min_q.empty() && num > min_q.top()) min_q.push(num);
        else max_q.push(num);
    }
    
    double findMedian() { // 查询中位数时，我尝试更新两个堆中元素，造成时间复杂度较高，最坏情况应该是O(nlogn)
        int n = cnt % 2 ? 1 : 0;
        while (max_q.size() > min_q.size() + n)
        {
            min_q.push(max_q.top());
            max_q.pop();
        }
        while (max_q.size() < min_q.size() + n)
        {
            max_q.push(min_q.top());
            min_q.pop();
        }
        if (cnt % 2) return max_q.top();
        else return (max_q.top() + min_q.top()) / 2.0;
    }
};