/*
72. 编辑距离
    给你两个单词 word1 和 word2， 请返回将 word1 转换成 word2 所使用的最少操作数  。
    你可以对一个单词进行如下三种操作：
    插入一个字符
    删除一个字符
    替换一个字符

    输入：word1 = "horse", word2 = "ros"
    输出：3
    解释：
    horse -> rorse (将 'h' 替换为 'r')
    rorse -> rose (删除 'r')
    rose -> ros (删除 'e')
*/


/*
    1）递归法
    动态规划+子序列问题，T=O(n^2)，S=O(n^2)
    记f[i][j]为将以i结尾的word1中的子串转换为以j结尾的word2中的子串所使用的最少操作数。
*/
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> f(n + 1, vector<int>(m + 1, 0));
        return dp(word1, n - 1, word2, m - 1, f);
    }
    int dp(string& w1, int i, string& w2, int j, vector<vector<int>>& f)
    {
        // 递归返回
        if (i < 0 && j < 0) return 0;
        if (i < 0) return j + 1;
        if (j < 0) return i + 1;

        // 重叠子问题直接返回
        if (f[i][j]) return f[i][j];

        // 状态转移
        int cnt = 0;
        if (w1[i] == w2[j])
        {
            cnt = dp(w1, i - 1, w2, j - 1, f);
        }
        else
        {
            cnt = 1 + min(dp(w1, i - 1, w2, j - 1, f), min(dp(w1, i - 1, w2, j, f), dp(w1, i, w2, j - 1, f))); // 依次对应于 替换、删除和插入操作
        }

        // 记忆化
        f[i][j] = cnt;

        // 得到结果
        return cnt;
    }
};

/*
    2）迭代计算
    动态规划+子序列问题，T=O(n^2)，S=O(n^2)
*/
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> f(n + 1, vector<int>(m + 1, 0)); // 注意我们多申请了一个空间，目的是把0为止空出来做初值

        // 初始值
        f[0][0] = 0;
        for (int i = 1; i <= n; i++)
        {
            f[i][0] = i;
        }
        for (int j = 1; j <= m; j++)
        {
            f[0][j] = j;
        }

        // 状态转移
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (word1[i - 1] == word2[j - 1]) // 状态转移方程里的i和j对应字符串中的i-1和j-1
                {
                    f[i][j] = f[i - 1][j - 1];
                }
                else
                {
                    f[i][j] = 1 + min(f[i - 1][j - 1], min(f[i - 1][j], f[i][j - 1]));
                }
            }
        }
        return f[n][m];
    }
};