// 84. 柱状图中最大的矩形


/*
    单调栈，T=O(n)，S=O(n)
    以每个柱子的高度计算其构成的最大矩形，最大的矩形就在其中。
    那么我们需要知道这个柱子往左和往右最多能扩展到多远，即往左或者往右找到第一个比它小的柱子为止，因此栈是单调递增的。
*/
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> sk;
        int n = heights.size();
        vector<int> left(n), right(n);
        for (int i = 0; i < n; ++i)
        {
            while (!sk.empty() && heights[sk.top()] >= heights[i])
            {
                sk.pop();
            }
            left[i] = sk.empty() ? -1 : sk.top(); // 如果栈为空，说明这个柱子就是最高的，赋值为-1
            sk.push(i);
        }

        sk = stack<int>();
        for (int j = n - 1; j >= 0; --j)
        {
            while (!sk.empty() && heights[sk.top()] >= heights[j])
            {
                sk.pop();
            }
            right[j] = sk.empty() ? n : sk.top();
            sk.push(j);
        }

        int res = 0;
        for (int i = 0; i < n; i++)
        {
            res = max(res, heights[i] * (right[i] - left[i] - 1));
        }
        return res;
    }
};