// 剑指 Offer 57. 和为s的两个数字

/*
    1）hash算法，T=O(n), S=O(n)
*/

/*
    2）双指针，T=O(n), S=O(1)
    由于数组是有序的，所以可以使用双指针将空间复杂度缩减
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size(), i = 0, j = n - 1;
        while (i < j)
        {
            if (nums[i] + nums[j] < target) i++;
            else if (nums[i] + nums[j] > target) j--;
            else return vector<int>{nums[i], nums[j]};
        }
        return vector<int>{};
    }
};