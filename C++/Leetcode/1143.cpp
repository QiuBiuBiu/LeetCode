/*
1143. 最长公共子序列
    给定两个字符串 text1 和 text2，返回这两个字符串的最长 公共子序列 的长度。如果不存在 公共子序列 ，返回 0 。
    一个字符串的 子序列 是指这样一个新的字符串：它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串。

    例如，"ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde" 的子序列。
    两个字符串的 公共子序列 是这两个字符串所共同拥有的子序列。

    输入：text1 = "abcde", text2 = "ace" 
    输出：3  
    解释：最长公共子序列是 "ace" ，它的长度为 3 。
*/

/*
    1）递归法
    动态规划，T=O(n^2), S=O(n^2)
*/
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> f(n, vector<int>(m, 0));
        return dp(text1, n - 1, text2, m - 1, f);
    }
    int dp(string& t1, int i, string& t2, int j, vector<vector<int>>& f)
    {
        if (i < 0 || j < 0) return 0;
        if (f[i][j]) return f[i][j];
        
        int cnt = 0;
        if (t1[i] == t2[j]) cnt = 1 + dp(t1, i - 1, t2, j - 1, f);
        else cnt = max(dp(t1, i - 1, t2, j, f), dp(t1, i, t2, j - 1, f));
        f[i][j] = cnt;
        return cnt;
    }
};

/*
    2）迭代法
    动态规划，T=O(n^2), S=O(n^2)
*/
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> f(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i < n; i++) f[i][0] = 0;
        for (int j = 0; j < m; j++) f[0][j] = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (text1[i - 1] == text2[j - 1]) f[i][j] = f[i - 1][j - 1] + 1;
                else f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            }
        }
        return f[n][m];
    }
};