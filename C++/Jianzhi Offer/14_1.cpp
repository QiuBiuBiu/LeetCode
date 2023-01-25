// 剑指 Offer 14- I. 剪绳子

/*
    1）动态规划，T=O(n^2)
    记f[n]表示长度为k的绳子切m（m>1）段的最大乘积，则有f[n]=max(f[j] * (n-j)) (1 < j < n)
    可以理解为先切一刀，得到n-j长的绳子，则余下的最大连乘积为f[j]之前已被计算过
*/

class Solution {
public:
    int cuttingRope(int n) {
        if (n == 1) return 1;
        if (n == 2) return 1;
        if (n == 3) return 2;

        vector<int> f(n + 1);
        f[1] = 1; f[2] = 2; f[3] = 3;
        for (int i = 4; i <= n; i++)
        {
            int Max = 0;
            for (int j = 1; j < i; j++)
            {
                Max = max(Max, f[j] * (i - j));
            }
            f[i] = Max;
        }
        
        return f[n];
    }
};

/*
    2）数学（贪心），T=O(1)
    当n>=5时，应尽可能多的剪长度为3的绳子 （可以由3(n-3）> n, 2(n-2) > n, 且3(n-3) > 2(n-2)证明得出）
    当n=4时，应将绳子剪成两段为2的绳子
*/
class Solution {
public:
    int cuttingRope(int n) {
        if (n == 1) return 1;
        if (n == 2) return 1;
        if (n == 3) return 2;

        int cnt2 = 0, cnt3 = 0;
        while (n % 3)
        {
            n -= 2;
            cnt2++;
        }
        cnt3 = n / 3;
        int res = pow(3, cnt3) * pow(2, cnt2);
        return res;
    }
};