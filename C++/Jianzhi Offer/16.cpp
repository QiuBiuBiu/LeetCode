// 剑指 Offer 16. 数值的整数次方

/*
    快速幂，递归法，T=O(logn), S=O(n)
*/

class Solution {
public:
    double myPow(double x, int n) {
        long long N = n; 
        return n > 0 ? getPow(x, n) : 1 / getPow(x, -N); // -2^31 <= n <= 23^1 - 1，当n为int的最小负数时，转换成正数会溢出
    }
    double getPow(double x, long long n)
    {
        if (n == 0) return 1;
        else if (n == 1) return x;

        double y = getPow(x, n / 2);
        return n % 2 ? y * y * x : y * y;
    }
};

/*
    快速幂，非递归法，T=O(logn), S=O(1)
    此方法的解析查看：https://leetcode.cn/problems/shu-zhi-de-zheng-shu-ci-fang-lcof/solutions/1398793/shu-zhi-de-zheng-shu-ci-fang-by-leetcode-yoqr/
*/
class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        return n > 0 ? getPow(x, n) : 1 / getPow(x, -N);
    }
    double getPow(double x, long long N)
    {
        double res = 1;
        while (N)
        {
            if (N & 1) res *= x;            
            x *= x;
            N >>= 1;
        }
        return res;
    }
};