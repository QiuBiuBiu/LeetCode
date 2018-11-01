/*
思路：
    数学，找规律……
    因为是找递增的下一个排列，所以从后往前找到第一个升序对的位置，如1,2,4,3,1.
    从后向前找就是2,4,3,1.因为2比前一个数4小，所以就锁定2这个数。
    之后就是在4,3,1中找到比2大的最小的那个数3（而且可证明找到的第一个比其大的数就是我们要找的数）
    将3与2对换得到降序排列4,2,1.然后就是将4,2,1反序得到1,2,4.最终结果就是1,3,1,2,4.
*/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), i = n - 1, k = n - 1;
        while(i > 0 && nums[i - 1] >= nums[i])
            i--;
        if (i > 0) {
            while (k >= i && nums[k] <= nums[i - 1])
                k--;
            swap(nums[i - 1], nums[k]);
            reverse(nums.begin() + i, nums.end());
        }
        else {
            reverse(nums.begin(), nums.end());
        }
    }
};