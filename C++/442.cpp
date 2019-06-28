class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        for (int i = 0; i < n; i++) {
            int val = abs(nums[i]) - 1;
            if (nums[val] > 0)
                nums[val] = -nums[val];
            else
                res.push_back(abs(nums[i]));
        }
        return res;
    }
};