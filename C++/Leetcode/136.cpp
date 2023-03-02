// 136. 只出现一次的数字
// 给你一个 非空 整数数组 nums ，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。


/*
    位运算，异或
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            res ^= nums[i];
        }
        return res;
    }
};
