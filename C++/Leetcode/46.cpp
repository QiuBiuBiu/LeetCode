// 46. 全排列
// 给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。


/*
    回溯法，T=O(n*n!)
*/
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
        dfs(nums, 0);
        return res;
    }
    void dfs(vector<int>& nums, int k)
    {
        if (k == nums.size())
        {
            res.emplace_back(nums);
            return ;
        }
        for (int i = k; i < nums.size(); i++)
        {
            swap(nums[k], nums[i]);
            dfs(nums, k + 1);
            swap(nums[k], nums[i]);
        }
    }
};


/*
    回溯法，T=O(n*n!)
*/
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> vis(nums.size(), 0);
        vector<int> path;
        dfs(nums, 0, path, vis);
        return res;
    }
    void dfs(vector<int>& nums, int cnt, vector<int>& path, vector<int>& vis)
    {
        if (cnt == nums.size())
        {
            res.emplace_back(path);
            return ;
        }
        for (int i = 0; i < nums.size(); i++)  // 每次从0开始枚举
        {
            if (vis[i] == 0) // 需要借助vis数组来判断是否该数字被取过
            {
                vis[i] = 1;
                path.emplace_back(nums[i]);
                dfs(nums, cnt + 1, path, vis);
                path.pop_back();
                vis[i] = 0;
            }  
        }
    }
};