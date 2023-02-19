// 40. 组合总和 II


/*
    回溯法，T=O(n*2^n)
    与39题的区别在于candidates中有重复的，并且candidates 中的每个数字在每个组合中只能使用 一次 ，而返回结果不能包含重复的组合
*/
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); // 先排序
        vector<int> path;
        dfs(candidates, 0, target, path);
        return res;
    }
    void dfs(vector<int>& candidates, int st, int target, vector<int>& path)
    {
        //if (target < 0) return ;
        if (target == 0)
        {
            res.emplace_back(path);
            return ;
        }
        for (int i = st; i < candidates.size(); i++)
        {
            if (target - candidates[i] < 0) break; // 剪枝
            if (i == st || candidates[i] != candidates[i - 1]) // 剪枝去重
            {
                path.emplace_back(candidates[i]);
                dfs(candidates, i + 1, target - candidates[i], path);
                path.pop_back();
            }
        }
    }
};