// 154. 寻找旋转排序数组中的最小值 II


/*
    二分，T=O(logn)，S=O(1)
    与153题不同一点是这题中会有重复的数字出现，此时有指针减一并不会丢失最小值（但因此最差情况T=O(n)）
    最终i=j，返回任意一个即可
    证明详情：https://leetcode.cn/problems/find-minimum-in-rotated-sorted-array-ii/solutions/9474/154-find-minimum-in-rotated-sorted-array-ii-by-jyd/
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