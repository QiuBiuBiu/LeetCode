// 70. 爬楼梯


/*
    DP
*/
class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        vector<int> f(n + 1, 0);
        f[1] = 1, f[2] = 2;
        for (int i = 3; i <= n; i++)
        {
            f[i] = f[i - 1] + f[i - 2];
        }
        return f[n];
    }
};