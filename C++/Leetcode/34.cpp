// 34. 在排序数组中查找元素的第一个和最后一个位置
// 给你一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。请你找出给定目标值在数组中的开始位置和结束位置。



/*
    二分，T=O(logn)，S=O(1)
    此题可以总结二分的模版
    1) 当更新right = mid时，mid应为 = (right - left) / 2 + left，最后return left
    2) 当更新left = mid时，mid应为 = (right - left + 1) / 2 + left， 最后return right
    用只有两个数的极端情况推理，如果不是上面的组合，二分算法都会陷入while死循环。
*/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = helperLeft(0, nums.size() - 1, nums, target);
        int right = helperRight(0, nums.size() - 1, nums, target);
        if (left >= 0 && left < nums.size() && nums[left] == target) return vector<int> {left, right};
        return vector<int> {-1, -1};
    }
    int helperLeft(int left, int right, vector<int>& nums, int target)
    {
        while (left < right)
        {
            int mid = (right - left) / 2 + left;
            if (nums[mid] > target) right = mid - 1;
            else if (nums[mid] < target) left = mid + 1;
            else right = mid; // 当更新right = mid时，mid应为 = (right - left) / 2 + left，最后return left
        }
        return left;
    }
    int helperRight(int left, int right, vector<int>& nums, int target)
    {
        while (left < right)
        {
            int mid = (right - left + 1) / 2 + left;
            if (nums[mid] > target) right = mid - 1;
            else if (nums[mid] < target) left = mid + 1;
            else left = mid; // 当更新left = mid时，mid应为 = (right - left + 1) / 2 + left， 最后return right
        }
        return right;
    }
};