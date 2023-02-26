// 96. 不同的二叉搜索树
// 给你一个整数 n ，求恰由 n 个节点组成且节点值从 1 到 n 互不相同的 二叉搜索树 有多少种？返回满足题意的二叉搜索树的种数。


/*
    动态规划
    由95题的思路发现会TLE，故加上记忆化的操作
*/
class Solution {
public:
    int numTrees(int n) {
        vector<vector<int>> f(n + 1, vector<int>(n + 1, 0));
        return dp(1, n, f);
    }
    int dp(int i, int j, vector<vector<int>>& f)
    {
        if (i >= j)
        {
            return 1;
        }
        if (f[i][j]) return f[i][j]; // 记忆化

        int res = 0;
        for (int k = i; k <= j; k++)
        {
            int left = dp(i, k - 1, f);
            int right = dp(k + 1, j, f);

            res += left * right;
        }
        f[i][j] = res; // 记忆化
        return res;
    }
};

/*
    动态规划
    二叉树的种类不受区间的影响，因此可以将记忆化的数组降为一维
*/
class Solution {
public:
    int numTrees(int n) {
        vector<int> f(n + 1, 0);
        return dp(1, n, f);
    }
    int dp(int i, int j, vector<int>& f)
    {
        if (i >= j)
        {
            return 1;
        }
        if (f[j - i + 1]) return f[j - i + 1];

        int res = 0;
        for (int k = i; k <= j; k++)
        {
            int left = dp(i, k - 1, f);
            int right = dp(k + 1, j, f);

            res += left * right;
        }
        f[j - i + 1] = res;
        return res;
    }
};

/*
    动态规划，迭代实现
    f[i]的结果也被称为卡特兰数：
    1 1 2 5 14 42 132 429 1430 4862 16796 58786 208012 742900 2674440 9694845 35357670 129644790 477638700 1767263190
*/
class Solution {
public:
    int numTrees(int n) {
        vector<int> f(n + 1, 0);
        f[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= i - 1; j++)
            {
                f[i] += f[j] * f[i - 1 - j];
            }
        }
        return f[n];
    }
};