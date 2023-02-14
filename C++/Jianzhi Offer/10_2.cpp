// 剑指 Offer 10- II. 青蛙跳台阶问题

class Solution {
public:
    int numWays(int n) {
        if (n == 0) return 1;
        else if (n == 1) return 1;
        vector<int> f(n + 1);
        f[0] = 1, f[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            f[i] = (f[i - 1] + f[i - 2]) % 1000000007;
        }
        return f[n];
    }
};