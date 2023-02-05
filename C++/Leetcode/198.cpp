/*
198. 打家劫舍
    你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
    给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。

    输入：[1,2,3,1]
    输出：4
    解释：偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
        偷窃到的最高金额 = 1 + 3 = 4 。
*/

/*
    1）dp，迭代法，T=O(n)，S=O(n)
    定义dp[i]的状态为从第0个房子到第i个房子能打劫到的最多的钱，
    则dp[i]的最大值考虑打不打劫第i个房子，
    故状态转移方程为f[i] = max(f[i - 1], f[i - 2] + nums[i]);
*/
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n);
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];
        
        f[0] = nums[0];
        f[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++) {
            f[i] = max(f[i - 1], f[i - 2] + nums[i]);
        }
        return f[n - 1];
    }
};

/*
    1）dp，递归法，T=O(n)，S=O(n)
    定义dp[i]的状态为从第0个房子到第i个房子能打劫到的最多的钱，
    则dp[i]的最大值考虑打不打劫第i个房子，
    故状态转移方程为f[i] = max(f[i - 1], f[i - 2] + nums[i]);
*/
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n, -1); // 注意递归法这里最好初始化为-1而不是0，因为有房子存在没有钱的情况
        return dp(n - 1, nums, f);
    }
    int dp(int i, vector<int>& nums, vector<int>& f)
    {
        if (i < 0) return 0;
        if (f[i] >= 0) return f[i]; // >= 0 即说明即使是空房子，我们也打劫过了做了记忆化，不然如果全是0的case，每一次都得到栈底才能返回，会造成TLE

        int money = max(dp(i - 1, nums, f), dp(i - 2, nums, f) + nums[i]);
        f[i] = money;
        return money;
    }
};