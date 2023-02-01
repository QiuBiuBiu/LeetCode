/*
思路：
    预处理：前i项和
*/
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }
        int t = 0;
        for (int i = 0; i < n; i++) {
            t += i == 0 ? 0 : nums[i - 1];
            if (t == sum - t - nums[i])
                return i;
        }
        return -1;
    }
};