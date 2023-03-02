// 200. 岛屿数量


/*
    dfs求连通集，T=O(nm), S=O(n)
*/
class Solution {
public:
    int N, M;
    int numIslands(vector<vector<char>>& grid) {
        N = grid.size();
        M = grid[0].size();
        int res = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (grid[i][j] == '1')
                {
                    ++res;
                    dfs(grid, i, j);
                }
            }
        }
        return res;
    }
    vector<vector<int>> dir{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    void dfs(vector<vector<char>>& grid, int x, int y)
    {
        if (x >= 0 && x < N && y >= 0 && y < M && grid[x][y] == '1')
        {
            grid[x][y] = '0';
            for (int i = 0; i < 4; ++i)
            {
                int newX = x + dir[i][0];
                int newY = y + dir[i][1];
                dfs(grid, newX, newY);
            }
        }
    }
};