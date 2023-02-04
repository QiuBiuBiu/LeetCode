/*
712. 两个字符串的最小ASCII删除和
    给定两个字符串s1 和 s2，返回 使两个字符串相等所需删除字符的 ASCII 值的最小和 。

    输入: s1 = "sea", s2 = "eat"
    输出: 231
    解释: 在 "sea" 中删除 "s" 并将 "s" 的值(115)加入总和。
    在 "eat" 中删除 "t" 并将 116 加入总和。
    结束时，两个字符串相等，115 + 116 = 231 就是符合条件的最小和
*/

/*
    1）递归法
    动态规划+子序列问题，T=O(n^2)，S=O(n^2)
    记f[i][j]为将以i结尾的word1中的子串转换(删除任意字符串中的任意字符)为以j结尾的word2中的子串所使用的最小ASCII删除和。
    PS: 583题的变形
*/
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> f(n, vector<int>(m, 0));
        return dp(s1, n - 1, s2, m - 1, f);
    }
    int getSum(string& str, int n)
    {
        int sum = 0;
        for (int i = 0; i <= n; i++)
            sum += str[i];
        return sum;
    }
    int dp(string& w1, int i, string& w2, int j, vector<vector<int>>& f)
    {
        if (i < 0 && j < 0) return 0;
        if (i < 0) return getSum(w2, j);
        if (j < 0) return getSum(w1, i);
        if (f[i][j]) return f[i][j];

        int sum = 0;
        if (w1[i] == w2[j])
        {
            sum = dp(w1, i - 1, w2, j - 1, f);
        }
        else
        {
            sum = min(dp(w1, i, w2, j - 1, f) + w2[j], dp(w1, i - 1, w2, j, f) + w1[i]);
        }
        f[i][j] = sum;
        return sum;
    }
};