// 90. 子集 II
// 给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的子集（幂集）。
// 解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。


/*
    回溯法，T=O(n*2^n)
    与78题的区别在于可能有重复元素，并且结果不能包含重复子集
*/
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> path;
        sort(nums.begin(), nums.end()); // 先排序
        dfs(nums, 0, path);
        return res;
    }
    void dfs(vector<int>& nums, int k, vector<int>& path)
    {
        res.emplace_back(path);
        for (int i = k; i < nums.size(); i++)
        {
            if (i == k || nums[i] != nums[i - 1]) // 去重
            {
                path.emplace_back(nums[i]);
                dfs(nums, i + 1, path);
                path.pop_back();                  
            }
        }
    }
};