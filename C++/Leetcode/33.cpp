// 33. 搜索旋转排序数组


/*
    二分，T=O(logn)，S=O(1)
    由153题可知，我们可以通过二分来找到旋转排序数组的最小值。
    那么我们可以先找到最小值，然后以它将数组分成两段，则两段都是有序的，然后再做一次二分既可找到target
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i = 0, j = nums.size() - 1;
        while (i < j)
        {
            int mid = (j - i) / 2 + i;
            if (nums[mid] > nums[j]) i = mid + 1;
            else j = mid;
        }

        if (i == 0 || target < nums[0]) // 搜索后一段有两种情况：1）最小值在数组中间，数组被分割成了 较大的一部分 和 较小的一部分 2）整个数据完全旋转了，即整体有序了，即i=0
            return helper(i, nums.size() - 1, nums, target);
        return helper(0, i - 1, nums, target);

    }
    int helper(int left, int right, vector<int>& nums, int target)
    {
        while (left < right)
        {
            int mid = (right - left) / 2 + left;
            if (nums[mid] > target) right = mid - 1;
            else if (nums[mid] < target) left = mid + 1;
            else return mid;
        }
        if (left < nums.size() && nums[left] == target) return left;
        return -1;
    }
};