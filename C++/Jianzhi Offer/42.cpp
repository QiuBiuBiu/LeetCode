// 剑指 Offer 42. 连续子数组的最大和
//输入一个整型数组，数组中的一个或连续多个整数组成一个子数组。求所有子数组的和的最大值。


/*
    DP，T=O(n)，S=O(1)
    见leetcode 53题
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int preMax = nums[0], res = preMax;
        for (int i = 1; i < nums.size(); i++)
        {
            preMax = max(nums[i], preMax + nums[i]);
            res = max(res, preMax);
        }
        return res;
    }
};