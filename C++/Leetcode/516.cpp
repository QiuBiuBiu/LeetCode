/*
516. 最长回文子序列
    给你一个字符串 s ，找出其中最长的回文子序列，并返回该序列的长度。
    子序列定义为：不改变剩余字符顺序的情况下，删除某些字符或者不删除任何字符形成的一个序列。

    输入：s = "bbbab"
    输出：4
    解释：一个可能的最长回文子序列为 "bbbb" 。
*/


/*
    1）递归法
    动态规划，T=O(n^2), S=O(n^2)
    记dp[i][j]为字符串s中i到j的最长回文子序列，比较s[i]和s[j]的值推导状态转移方程
*/
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> f(n, vector<int>(n, 0));
        return dp(s, 0, n - 1, f);
    }
    int dp(string& s, int i, int j, vector<vector<int>>& f)
    {
        // 初值，返回
        if (i == j) return 1;
        if (i > j) return 0;
        if (f[i][j]) return f[i][j];

        int len = 0;
        // 状态转移
        if (s[i] == s[j]) len = 2 + dp(s, i + 1, j - 1, f);
        else len = max(dp(s, i + 1, j, f), dp(s, i, j - 1, f));

        // 记忆化
        f[i][j] = len;
        return len;
    }
};


/*
    2）迭代法
    动态规划，T=O(n^2), S=O(n^2)
    记dp[i][j]为字符串s中i到j的最长回文子序列，比较s[i]和s[j]的值推导状态转移方程
*/
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> f(n + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= n; i++) f[i][i] = 1;
        for (int i = n; i >= 1; i--)
        {
            for (int j = i + 1; j <= n; j++)
            {
                if (s[i - 1] == s[j - 1]) f[i][j] = 2 + f[i + 1][j - 1];
                else f[i][j] = max(f[i + 1][j], f[i][j - 1]);
            }
        }
        return f[1][n];
    }
};