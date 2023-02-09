/*
11. 盛最多水的容器
    给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。
    找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
    返回容器可以储存的最大水量。

    输入：[1,8,6,2,5,4,8,3,7]
    输出：49 
    解释：图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。
*/


/*
    双指针+贪心，T=O(n)，S=O(1)
    在每个阶段，长板或短板向中间收窄一格，都会导致水槽底边宽度−1变短：
    若 移动短板，水槽的短板 min(h[i],h[j]) 可能变大，因此下个水槽的面积 可能增大 。
    若 移动长板，水槽的短板 min(h[i],h[j]) 不变或变小，因此下个水槽的面积 一定变小 。
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        for (int i = 0, j = height.size() - 1; i < j; ) 
        {
            if (height[i] < height[j]) 
            {
                ans = max(ans, height[i] * (j - i));
                i++;
            }
            else
            {
                ans = max(ans, height[j] * (j - i));
                j--;
            }
        }
        return ans;
    }
};