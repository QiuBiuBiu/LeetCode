// 剑指 Offer 14- II. 剪绳子 II

/*
    此题跟14_1.cpp的思路一样，只不过n的值更大，且需要对结果取模
*/

class Solution {
public:
    int cuttingRope(int n) {
        if (n < 4) return n - 1;
        int cnt3 = 0, cnt2 = 0;
        while (n % 3)
        {
            n -= 2;
            cnt2++;
        }
        cnt3 = n / 3;
        long long res = 1; // 可能会溢出
        for (int i = 0; i < cnt2; i++) res *= 2;
        for (int i = 0; i < cnt3; i++)
        {
            res *= 3;
            if (res > 1000000007) res %= 1000000007;
        }
        return static_cast<int>(res);
    }
};