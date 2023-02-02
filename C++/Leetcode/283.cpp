/*
283. 移动零
    给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
    请注意，必须在不复制数组的情况下原地对数组进行操作。

    输入: nums = [0,1,0,3,12]
    输出: [1,3,12,0,0]
*/


/*
    双指针+原地修改，T=O(n)，S=O(1)
*/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = -1;
        for (int j = 0; j < nums.size(); j++)
        {
            if (nums[j] != 0) nums[++i] = nums[j]; // 记录非0值
        }
        for (int j = i + 1; j < nums.size(); j++) 
        {
            nums[j] = 0; // 覆盖0
        }
    }
};