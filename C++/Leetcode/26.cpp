class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0, j = 0, n = nums.size();
        while (i < n) {
            while (nums[++j] == nums[i]) 
                ;
            if (j < n)
                nums[++i] = nums[j];
            else
                return i + 1;
        }
        return i;
    }
};