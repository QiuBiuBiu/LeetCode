// 剑指 Offer 10- I. 斐波那契数列


class Solution {
public:
    int fib(int n) {
        vector<int> f(n + 1);
        if (n == 0) return 0;
        else if (n == 1) return 1;
        f[0] = 0, f[1] = 1;
        int MOD = 1000000007;
        for (int i = 2; i <= n; i++)
        {
            f[i] = (f[i - 1] + f[i - 2]) % MOD;
        }
        return f[n];
    }
};