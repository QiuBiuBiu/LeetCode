// 剑指 Offer 21. 调整数组顺序使奇数位于偶数前面


/*
    双指针，T=O(n), S=O(1)
*/
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = n - 1;
        while (i < j)
        {
            while (i < j)
            {
                if (nums[i] % 2 == 0) break;
                else i++;
            }
            while (i < j)
            {
                if (nums[j] % 2) break;
                else j--;
            }
            swap(nums[i], nums[j]);
        }
        return nums;
    }
};