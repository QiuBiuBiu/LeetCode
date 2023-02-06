/*
740. 删除并获得点数
    给你一个整数数组 nums ，你可以对它进行一些操作。
    每次操作中，选择任意一个 nums[i] ，删除它并获得 nums[i] 的点数。之后，你必须删除 所有 等于 nums[i] - 1 和 nums[i] + 1 的元素。
    开始你拥有 0 个点数。返回你能通过这些操作获得的最大点数。

    输入：nums = [3,4,2]
    输出：6
    解释：
    删除 4 获得 4 个点数，因此 3 也被删除。
    之后，删除 2 获得 2 个点数。总共获得 6 个点数。
*/


/*
    动态规划，T=O(n), S=O(n)
    PS：198题 打家劫舍 的变形。
*/
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];

        int Max = 0;
        for (const auto& a: nums)
            Max = max(Max, a);
        if (Max == 1) return nums.size();

        vector<int> cnt(Max + 1);
        for (const auto& a: nums) // 预处理，变成打家劫舍
            ++cnt[a];

        vector<int> f(Max + 1, 0);
        f[1] = cnt[1], f[2] = max(cnt[2] * 2, f[1]);
        for (int i = 2; i < Max + 1; i++)
        {
            f[i] = max(f[i - 1], i * cnt[i] + f[i - 2]);
        }
        return f[Max];
    }
};

