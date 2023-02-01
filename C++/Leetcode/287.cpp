class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size(), le = 1, ri = n - 1;
        while (le < ri) {
            int mid = (le + ri) >> 1;
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                if (nums[i] <= mid) cnt++;
            }
            if (cnt <= mid) le = mid + 1;
            else ri = mid;
        }
        return le;
    }
};