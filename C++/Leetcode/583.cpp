/*
583. 两个字符串的删除操作
    给定两个单词 word1 和 word2 ，返回使得 word1 和  word2 相同所需的最小步数。
    每步 可以删除任意一个字符串中的一个字符。

    输入: word1 = "sea", word2 = "eat"
    输出: 2
    解释: 第一步将 "sea" 变为 "ea" ，第二步将 "eat "变为 "ea"
*/


/*
    1）递归法
    动态规划+子序列问题，T=O(n^2)，S=O(n^2)
    记f[i][j]为将以i结尾的word1中的子串转换(删除任意字符串中的任意字符)为以j结尾的word2中的子串所使用的最少操作数。
    PS: 72题的简化版
*/
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> f(n, vector<int>(m, 0));
        return dp(word1, n - 1, word2, m - 1, f);
    }
    int dp(string& w1, int i, string& w2, int j, vector<vector<int>>& f)
    {
        if (i < 0 && j < 0) return 0;
        if (i < 0) return j + 1;
        if (j < 0) return i + 1;
        if (f[i][j]) return f[i][j];

        int cnt = 0;
        if (w1[i] == w2[j])
        {
            cnt = dp(w1, i - 1, w2, j - 1, f);
        }
        else
        {
            cnt = 1 + min(dp(w1, i, w2, j - 1, f), dp(w1, i - 1, w2, j, f));
        }
        f[i][j] = cnt;
        return cnt;
    }
};