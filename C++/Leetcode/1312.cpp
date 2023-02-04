/*
1312. 让字符串成为回文串的最少插入次数
    给你一个字符串 s ，每一次操作你都可以在字符串的任意位置插入任意字符。
    请你返回让 s 成为回文串的 最少操作次数 。
    「回文串」是正读和反读都相同的字符串。

    输入：s = "zzazz"
    输出：0
    解释：字符串 "zzazz" 已经是回文串了，所以不需要做任何插入操作。
*/


/*
    1）递归法
    动态规划，T=O(n^2), S=O(n^2)
    记dp[i][j]为字符串s中i到j成为回文串的最少插入次数，比较s[i]和s[j]的值推导状态转移方程。
    PS: 516题变形
*/
class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>> f(n, vector<int>(n, 0));
        return dp(s, 0, n - 1, f);
    }
    int dp(string& s, int i, int j, vector<vector<int>>& f)
    {
        if (i == j) return 0;
        if (i > j) return 0;
        if (f[i][j]) return f[i][j];

        int cnt = 0;
        if (s[i] == s[j]) cnt = dp(s, i + 1, j - 1, f);
        else cnt = 1 + min(dp(s, i + 1, j, f), dp(s, i, j - 1, f));
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
    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>> f(n + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= n; i++) f[i][i] = 0;
        for (int i = n; i >= 1; i--)
        {
            for (int j = i + 1; j <= n; j++)
            {
                if (s[i - 1] == s[j - 1]) f[i][j] = f[i + 1][j - 1];
                else f[i][j] = 1 + min(f[i + 1][j], f[i][j - 1]);
            }
        }
        return f[1][n];
    }
};