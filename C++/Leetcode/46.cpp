// 46. 全排列
// 给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。


/*
    回溯法
*/
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
        perm(nums, 0, nums.size() - 1);
        return res;
    }
    void perm(vector<int>& a, int s, int e) {
        if (s == e) {
            res.push_back(a);
            return ;
        }
        for (int i = s; i <= e; i++) {
            swap(a[i], a[s]);
            perm(a, s + 1, e);
            swap(a[i], a[s]);
        }
    }
};


/*
    回溯法
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