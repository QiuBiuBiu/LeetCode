/*
思路：
	二分
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return -1;
		// 先用二分通过num[n-1]找出最小值，也就是pivot
        int le = 0, ri = n - 1;
        while (le < ri) {
            int mid = (le + ri) >> 1;
            if (nums[mid] > nums[n - 1])
                le = mid + 1;
            else if (nums[mid] < nums[n - 1])
                ri = mid;
        }
		// 确定target在哪个区间
        if (target > nums[n - 1])
            le = 0;
        else {
            le = ri;
            ri = n - 1;
        }
		// 再次二分
        while(le <= ri) {
            int mid = (le + ri) >> 1;
            if (nums[mid] > target)
                ri = mid - 1;
            else if (nums[mid] < target)
                le = mid + 1;
            else
                return mid;
            
        }
        return -1;
    }
};