/*
15. 三数之和
    给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。请
    你返回所有和为 0 且不重复的三元组。
    注意：答案中不可以包含重复的三元组。
*/

/*
    排序+双指针，T=O(n^2)
    先排序，再固定一个数字nums[i]，用双指针来寻找另外两个数字
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        map<pair<int, int>, int> mp; // 用一个map来判重，当两个数字都出现过时，这三个数字的组合之前肯定出现过
        for (int i = 0; i < nums.size(); i++)
        {
            int target = -nums[i];
            if (target < 0) break; // 剪枝优化
            for (int j = i + 1, k = nums.size() - 1; j < k; )
            {
                if (nums[j] + nums[k] == target)
                {
                    auto tmp = pair<int, int>{nums[i], nums[j]};
                    if (mp.find(tmp) == mp.end())
                    {
                        res.push_back(vector<int>{nums[i], nums[j], nums[k]});
                        mp[tmp] = 1;
                    }
                    j++, k--;
                }
                else if (nums[j] + nums[k] > target) k--;
                else j++;
            }
        }
        return res;
    }
};