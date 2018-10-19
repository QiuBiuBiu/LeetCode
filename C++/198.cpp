/*
思路：dp
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