class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0, j = nums.size() - 1;
        for (int k = 0; k <= j; k++) {
            if (nums[k] == 0 && k != i)
                swap(nums[k--], nums[i++]);
            else if (nums[k] == 2 && k != j)
                swap(nums[k--], nums[j--]);
        }
    }
};