/*
16. 最接近的三数之和
    给你一个长度为 n 的整数数组 nums 和 一个目标值 target。请你从 nums 中选出三个整数，使它们的和与 target 最接近。
    返回这三个数的和。
    假定每组输入只存在恰好一个解。

    输入：nums = [-1,2,1,-4], target = 1
    输出：2
    解释：与 target 最接近的和是 2 (-1 + 2 + 1 = 2) 。
*/

/*
    排序+双指针，T=O(n^2)
    先排序，再固定一个数字nums[i]，用双指针来寻找另外两个数字
*/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1, k = nums.size() - 1; j < k; )
            {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == target) return sum;
                else if (sum > target) k--;
                else j++;
                
                if (abs(sum - target) < abs(res - target))
                {
                    res = sum;
                }
            }
        }
        return res;
    }
};