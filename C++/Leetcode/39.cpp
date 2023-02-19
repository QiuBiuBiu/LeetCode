// 39. 组合总和

/*
    回溯法，T=O(S)，其中 S 为所有可行解的长度之和。
    注意此题中 candidates 中的 同一个 数字可以 无限制重复被选取。
    与46，47题的区别在于此题中是可以重复选某个数的
*/
class Solution {
public:
    vector<vector<int>> paths;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> path;
        dfs(candidates, 0, target, path);
        return paths;
    }
    void dfs(vector<int>& candidates, int st, int target, vector<int>& path)
    {
        if (target < 0) return;
        if (target == 0)
        {
            paths.emplace_back(path);
        }
        for (int i = st; i < candidates.size(); i++)
        {
            path.emplace_back(candidates[i]);
            dfs(candidates, i, target - candidates[i], path); // 因为同一个数可以无限次取，所以这里递归传i
            path.pop_back();
        }
    }
};
