// 64. 最小路径和

/*
    DP，T=O(n^2)，S=O(n^2)
*/
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> f(m, vector<int>(n, 0));
        int sum = 0;
        for (int i = 0; i < m; i++) sum += grid[i][0], f[i][0] = sum;
        sum = 0;
        for (int j = 0; j < n; j++) sum += grid[0][j], f[0][j] = sum;

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                f[i][j] = min(f[i - 1][j], f[i][j - 1]) + grid[i][j];
            }
        }
        return f[m - 1][n - 1];
    }
};