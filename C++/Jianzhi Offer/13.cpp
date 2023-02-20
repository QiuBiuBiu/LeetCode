//剑指 Offer 13. 机器人的运动范围


/*
    搜索(dfs)
*/
class Solution {
public:
    int M, N;
    int movingCount(int m, int n, int k) {
        M = m, N = n;
        vector<vector<int>>vis (m, vector<int>(n, 0));
        return dfs(0, 0, k, vis);
    }
    vector<vector<int>> direction = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int dfs(int x, int y, int k, vector<vector<int>>& vis)
    {
        if (x >= 0 && x < M && y >= 0 && y < N && !vis[x][y] && check(x, y, k))
        {
            vis[x][y] = 1;
            int total = 1;
            for (int i = 0; i < 4; i++)
            {
                int new_x = x + direction[i][0];
                int new_y = y + direction[i][1];
                total += dfs(new_x, new_y, k, vis);
            }
            return total;
        }
        return 0;
    }

    bool check(int x, int y, int k)
    {
        int total = 0;
        while (x)
        {
            total += x % 10;
            x /= 10;
        }
        while (y)
        {
            total += y % 10;
            y /= 10;
        }
        return total <= k;
    }
};