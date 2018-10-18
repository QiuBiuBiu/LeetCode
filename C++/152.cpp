/*
思路：
    动态规划（dp）：
    与53.Maximum Subarry的状态及状态转移相似。
    只是由于负负相乘为正的关系，这里需要维护两个数组。
    最大值从其中一个数组中产生。
*/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(), ans = nums[0];
        // return dp(n, ans, nums);
        return dpSaveSpace(n, ans, nums);
    }
    int dp(int n, int ans, vector<int>& nums){
        vector<int> fmax(n), fmin(n);
        fmax[0] = fmin[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            fmax[i] = max(max(fmax[i - 1] * nums[i], fmin[i - 1] * nums[i]), nums[i]);
            fmin[i] = min(min(fmin[i - 1] * nums[i], fmax[i - 1] * nums[i]), nums[i]);
            ans = max(max(fmax[i], fmin[i]), ans);
        }
        return ans;
    }
    int dpSaveSpace(int n, int ans, vector<int>& a){
        int fmax = a[0], fmin = a[0];
        for (int i = 1; i < n; i++){
            int tmp = fmax;
            fmax = max(max(fmax * a[i], fmin * a[i]), a[i]);
            fmin = min(min(fmin * a[i], tmp * a[i]), a[i]);
            ans = max(max(fmax, fmin), ans);
        }
        return ans;
    }
};