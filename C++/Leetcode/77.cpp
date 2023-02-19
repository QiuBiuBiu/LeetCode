// 77. 组合
// 给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。
// 你可以按 任何顺序 返回答案。


/*
    回溯法，T=O(n*2^n)
*/
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combine(int n, int k) {
        vector<int> path;
        dfs(n, k, 1, 0, path);
        return res;
    }
    void dfs(int n, int k, int st, int cnt, vector<int>& path) // st记录开始枚举的位置，cnt记录已枚举的个数
    {
        if (cnt == k)
        {
            res.emplace_back(path);
            return ;
        }
        for (int i = st; i <= n; i++)
        {
            path.emplace_back(i);
            dfs(n, k, i + 1, cnt + 1, path);
            path.pop_back();
        }
    }
};