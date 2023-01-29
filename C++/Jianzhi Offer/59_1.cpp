// 剑指 Offer 59 - I. 滑动窗口的最大值

/*
    单调队列
    30.cpp中用单调栈的方法可以在O(1)的时间内获得最小(大)值，则对于滑动窗口这种FIFO的结构，我们使用单调队列。
    单调队列只存储有可能成为滑动窗口中的最大值：
    1）比当前滑动窗口之前的数都大
    2）比当前滑动窗口之前的数小，那么当前面的数被移除滑动窗口后，它有可能成为滑动窗口的最大值
    所以，我们可以推断出我们的队列中保存着一个单调递减的数列
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.empty()) return vector<int>{};

        deque<int> q; //使用双端队列来模拟滑动窗口
        // 初始化单调队列
        for (int i = 0; i < k; i++)
        {
            while (!q.empty() && nums[i] > nums[q.back()]) q.pop_back(); // 用nums[i]来更新单调队列
            q.push_back(i); // 队列中压入的是下标而不是数值本身，这是为了帮助后面检查这个数是否已经被移除了滑动窗口
        }

        vector<int> res;
        res.push_back(nums[q.front()]);
        // 得到所有滑动窗口的最大值
        for (int i = k; i < nums.size(); i++)
        {
            while (!q.empty() && i - q.front() + 1 > k) q.pop_front(); // 检查队列前段的最大值是否“过期”

            while (!q.empty() && nums[i] > nums[q.back()]) q.pop_back(); // 用nums[i]来更新单调队列
            q.push_back(i);

            res.push_back(nums[q.front()]);
        }
        
        return res;
    }
};