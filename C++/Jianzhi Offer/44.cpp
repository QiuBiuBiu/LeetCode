// 剑指 Offer 44. 数字序列中某一位的数字

/*
    利用10进制数字性质来求解：T=O(logn)
    个位数字（除0外）共有9个，十位数字共有90个，百位数字共有900个...
*/

class Solution {
public:
    int findNthDigit(int n) {
        if (n == 0) return 0;

        int k = 1, N = n;
        long long base = 9;
        while (N - base * k > 0)
        {
            N -= base * k;
            base *= 10;
            k++;
        }

        int num = N / k, mod = N % k; // k为所在数字区间的位数

        int firstNum = pow(10, k - 1); // 得到该位中的第一个数
        int realNum = firstNum + num - 1;

        if (mod > 0) realNum++, realNum /= pow(10, k - mod);
        return realNum % 10;
    }
};