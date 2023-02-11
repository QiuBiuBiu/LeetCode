// 剑指 Offer 11. 旋转数组的最小数字


/*
    二分，T=O(logn)，S=O(1)
    解析请看leetcode 154.
*/
class Solution {
public:
    int findMin(vector<int>& nums) {
        int i = 0, j = nums.size() - 1;
        while (i < j)
        {
            int mid = i + (j - i) / 2;
            if (nums[mid] > nums[j])
            {
                i = mid + 1;
            }
            else if (nums[mid] < nums[j])
            {
                j = mid;
            }
            else --j;
        }
        return nums[i];
    }
};