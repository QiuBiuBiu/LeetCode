/*
300. 最长递增子序列
    给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。
    子序列 是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列。
*/

/*
    1) 动态规划，T=O(n^2)，S=O(n)
    记f[i]为以i结尾的最长递增子序列。
*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int res = 1;
        vector<int> f(nums.size(), 1);
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i]) f[i] = max(f[i], f[j] + 1);
            }
            res = max(res, f[i]);
        }
        return res;
    }
};

/*
    2）二分法，T=O(nlogn)，S=O(n)
*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int k = -1;
        vector<int> cpy(nums.size());
        for (int i = 0; i < nums.size(); i++)
        {
            if (i == 0) cpy[++k] = nums[i];
            else
            {
                if (nums[i] > cpy[k]) cpy[++k] = nums[i];
                else
                {
                    int left = 0, right = k;
                    while (left != right)
                    {
                        int mid = (right - left) / 2 + left;
                        if (nums[i] > cpy[mid]) left = mid + 1;
                        else right = mid;
                    }
                    cpy[left] = nums[i];
                }
            }
        }
        return k + 1;
    }
};