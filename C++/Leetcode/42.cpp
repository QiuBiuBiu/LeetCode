// 42. 接雨水
// 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。


/*
    双指针，T=O(n), S=O(1)
*/
class Solution {
public:
    int trap(vector<int>& height) {
        int minH = 0, res = 0;
        for (int i = 0, j = height.size() - 1; i < j;)
        {
            minH = min(height[i], height[j]);
            if (height[i] >= height[j])
            {
                if (height[--j] < minH)
                {
                    res += minH - height[j];
                    height[j] = minH;
                }
            }
            else
            {
                if (height[++i] < minH)
                {
                    res += minH - height[i];
                    height[i] = minH;
                }
            }
        }
        return res;
    }
};

/*
    单调栈，T=O(n), S=O(n)
    0）维护一个栈，关键需要记录 比当前柱子更高的柱子的下标 idx。
    1）遍历每一个柱子，如果它不高于比栈顶的柱子，说明接不到雨水，直接进栈。
    2.1）否则，我们应不断弹出栈顶元素，直到我们找到比它更高的柱子（这就是为什么叫单调栈的原因，我们的栈内柱子的高度是单调递减的）
    2.2）同时我们需要计算被弹出的每一个柱子，在栈底和新柱子的包夹之下能接到的雨水量
    PS：此题跟84题类似
*/
class Solution {
public:
    struct node // 栈保存柱子的信息
    {
        int i; // 柱子所在的下标
        int idx; // 比当前柱子更高的柱子的下标
    };
    int trap(vector<int>& height) {
        stack<node> sk;
        int res = 0, skMax = 0; // skMax记录当前栈内最高柱子的高度，其实也就是栈底柱子的高度
        for (int i = 0; i < height.size(); ++i)
        {
            while (!sk.empty() && height[sk.top().i] < height[i]) // 2.1）如果当前柱子比栈顶的柱子还高，那么有可能接到雨水
            {
                // 2.2）对于每个栈顶柱子能接到雨水的量 = 当前柱子和栈内最高柱子的高度的小者 * (栈顶柱子的下标 - 比栈顶柱子的更高的柱子的下标)
                res += (min(height[i], skMax) - height[sk.top().i]) * (sk.top().i - sk.top().idx);
                sk.pop();
            }
            skMax = max(skMax, height[i]);
            node cur; cur.i = i, cur.idx = sk.empty() ? -1 : sk.top().i; // 0）如果栈为空，说明这个柱子就是最高的，idx = -1，否则idx应为栈顶柱子的下标i 
            sk.push(cur);
        }
        return res;
    }
};