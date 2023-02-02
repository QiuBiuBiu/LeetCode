/*
26. 删除有序数组中的重复项
    给你一个 升序排列 的数组 nums ，请你 原地 删除重复出现的元素，使每个元素 只出现一次 ，返回删除后数组的新长度。元素的 相对顺序 应该保持 一致 。
    不要使用额外的空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。

    输入：nums = [1,1,2]
    输出：2, nums = [1,2,_]
*/


/*
    双指针+原地修改，T=O(n)，S=O(1)
    对于需要原地修改的问题，我们使用指针k来记录应保留的数字index，然后用快/慢两个指针i和j来遍历整个数组；
    i记录一个相同数字的首部，j记录它的尾部，注意是一个[)
    当i和j指向的数字不同时，我们直接将其覆盖到指针k的指向中，即完成原地修改，然后用j更新i
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = -1, i = 0;
        for (int j = 0; j < nums.size();)
        {
            if (nums[i] == nums[j]) ++j;
            else
            {
                nums[++k] = nums[i];
                i = j;
            }
        }
        nums[++k] = nums[i]; // 最后一个元素
        return k + 1;
    }
};

