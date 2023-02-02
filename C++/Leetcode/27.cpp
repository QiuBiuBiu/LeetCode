/*
27. 移除元素
    给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。
    不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。

    输入：nums = [3,2,2,3], val = 3
    输出：2, nums = [2,2]
*/

/*
    双指针+原地修改，T=O(n)，S=O(1)
    慢指针i记录需要保留的数字，快指针j遍历整个数组，原地修改即用指针j对应的数字覆盖指针i对应的数字
*/
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = -1;
        for (int j = 0; j < nums.size(); ++j)
        {
            if (nums[j] != val) nums[++i] = nums[j];
        }
        return i + 1;
    }
};