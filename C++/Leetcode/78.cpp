// 78. 子集
// 给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。


/*
    回溯法，T=O(n*2^n)
*/
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> path;
        dfs(nums, 0, path);
        return res;
    }
    void dfs(vector<int>& nums, int k, vector<int>& path)
    {
        res.emplace_back(path);
        
        for (int i = k; i < nums.size(); i++)
        {
            path.emplace_back(nums[i]);
            dfs(nums, i + 1, path);
            path.pop_back();
        }
    }
};