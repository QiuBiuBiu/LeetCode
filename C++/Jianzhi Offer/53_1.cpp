// 剑指 Offer 53 - I. 在排序数组中查找数字 I
// 统计一个数字在排序数组中出现的次数。


/*
    二分， T=O(logn)，S=O(1)
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return 0;

        return find(nums, target) - find(nums, target - 1);
    }
    int find(vector<int>& nums, int t)
    {
        int i = 0, j = nums.size() - 1, res = -1;
        while (i <= j)
        {
            int mid = (j - i) / 2 + i;
            if (nums[mid] <= t)  
            {
                i = mid + 1;
                res = mid;
            }
            else j = mid - 1;
        }
        return res;
    }
};