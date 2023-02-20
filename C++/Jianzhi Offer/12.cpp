// 剑指 Offer 12. 矩阵中的路径


/*
    搜索(dfs)
*/
class Solution {
public:
    int n, m;
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        if (!n) return false;
        m = board[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                vector<vector<int>> vis(n, vector<int>(m, 0));
                if (dfs(i, j, 0, board, word, vis)) return true;
            }
        }
        return false;
    }
    vector<vector<int>> direction = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int dfs(int x, int y, int k, vector<vector<char>>& board, string& word, vector<vector<int>>& vis) // k记录匹配到了第几个字符
    {
        if (!(x >= 0 && x < n && y >= 0 && y < m && !vis[x][y] && board[x][y] == word[k])) return false;
        //cout << x << " " << y << " " << board[x][y] << " " << word[k] << endl;
        vis[x][y] = 1;
        if (k == word.size() - 1) return true;
        for (int i = 0; i < 4; i++)
        {
            int new_x = x + direction[i][0];
            int nex_y = y + direction[i][1];
            if (dfs(new_x, nex_y, k + 1, board, word, vis)) return true;
        }
        vis[x][y] = 0;
        return false; 
    }
};