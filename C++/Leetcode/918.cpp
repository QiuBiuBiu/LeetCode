/*
918. 环形子数组的最大和
    给定一个长度为 n 的环形整数数组 nums ，返回 nums 的非空 子数组 的最大可能和 。
    环形数组 意味着数组的末端将会与开头相连呈环状。形式上， nums[i] 的下一个元素是 nums[(i + 1) % n] ， nums[i] 的前一个元素是 nums[(i - 1 + n) % n] 。
    子数组 最多只能包含固定缓冲区 nums 中的每个元素一次。形式上，对于子数组 nums[i], nums[i + 1], ..., nums[j] ，不存在 i <= k1, k2 <= j 其中 k1 % n == k2 % n 。

    输入：nums = [1,-2,3,-2]
    输出：3
    解释：从子数组 [3] 得到最大和 3
*/

/*
    动态规划，T=O(n), S=O(1)
    PS：53题 最大子数组和 的升级。
    由分析可知：https://leetcode.cn/problems/maximum-sum-circular-subarray/solutions/1152143/wo-hua-yi-bian-jiu-kan-dong-de-ti-jie-ni-892u/ 
    环形子数组的最大和要么是：1）最大子数组和 2）数组总和 - 最小子数组和
    只有一种例外：当这数组的所有数都是负数时，此时1）的结果为某个负数，2）的结果为0，所以这里我们要做一下特殊处理
*/
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int preMax = nums[0], preMin = nums[0];
        int Max = nums[0], Min = nums[0], sum = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            sum += nums[i];
            preMax = max(preMax + nums[i], nums[i]);
            preMin = min(preMin + nums[i], nums[i]);
            Max = max(Max, preMax);
            Min = min(Min, preMin);
        }
        return Max > 0 ? max(Max, sum - Min) : Max;
    }
};