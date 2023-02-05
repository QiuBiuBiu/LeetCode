/*
213. 打家劫舍 II
    你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都 围成一圈 ，这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警 。
    给定一个代表每个房屋存放金额的非负整数数组，计算你 在不触动警报装置的情况下 ，今晚能够偷窃到的最高金额。

    输入：nums = [2,3,2]
    输出：3
    解释：你不能先偷窃 1 号房屋（金额 = 2），然后偷窃 3 号房屋（金额 = 2）, 因为他们是相邻的。
*/


/*
    1）dp，递归法，T=O(n)，S=O(n)
    题198的升级，我们将问题拆成两部分：
        1. 抢第n间房子，则不能抢第1和第n-1间，则有dp(n - 2) + nums[n]
        2. 不抢第n间房子，则问题回归到dp(n - 1)
*/
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n, -1);
        int robIncludeLast = dp(n - 3, 1, nums, f) + nums[n - 1];
        for (int i = 0; i < n; i++) f[i] = -1;
        int robExcludeLast = dp(n - 2, 0, nums, f);
        return max(robIncludeLast, robExcludeLast);
    }
    int dp(int i, int bottom, vector<int>& nums, vector<int>& f) // 注意这里的bottom，两次的返回条件的初始值是不一样的
    {
        if (i < bottom) return 0;
        if (f[i] >= 0) return f[i];

        int money = max(dp(i - 1, bottom, nums, f), dp(i - 2, bottom, nums, f) + nums[i]);
        f[i] = money;
        return money;
    }
};