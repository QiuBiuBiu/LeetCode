// 239. 滑动窗口最大值


/*
    单调队列
    解析见 剑指 Offer 59 - I
*/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        for (int i = 0; i < k; ++i)
        {
            while (!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();
            dq.push_back(i);
        }

        vector<int> res;
        res.emplace_back(nums[dq.front()]);

        for (int i = k; i < nums.size(); ++i)
        {
            while (!dq.empty() && i - dq.front() >= k) dq.pop_front();

            while (!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();
            dq.push_back(i);

            res.emplace_back(nums[dq.front()]);
        }
        return res;
    }
};