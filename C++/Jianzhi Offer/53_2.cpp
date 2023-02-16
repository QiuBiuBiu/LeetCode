// 剑指 Offer 53 - II. 0～n-1中缺失的数字
// 一个长度为n-1的递增排序数组中的所有数字都是唯一的，并且每个数字都在范围0～n-1之内。在范围0～n-1内的n个数字中有且只有一个数字不在该数组中，请找出这个数字。


/*
    二分，T=O(logn)，S=O(1)
    即找nums[i] != i的左边界
*/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = n - 1;
        while (i < j)
        {
            int m = i + (j - i) / 2;
            if (nums[m] == m) i = m + 1;
            else j = m;
        }
        if (nums[i] == i) return n;
        return i;
    }
};