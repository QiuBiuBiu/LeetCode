// 剑指 Offer 43. 1～n 整数中 1 出现的次数

/*
    递归算法，T=O(logn)
    以21345举例：
    1）首先我们统计首位为1的次数：要分别考虑首位数字大于1和等于1的情况。
    2）我们将21345分成1346～11345，11346～21345，1～1345三部分
    3）然后我们统计前两部分中1出现在非首位的次数：特别注意这两部分可以用排列组合计算，其结果都是2 * C(4, 1) * 10^3
    4）递归求解1～1345这部分
*/
class Solution {
public:
    int countDigitOne(int n) {
        string num = "";
        while (n)
        {
            char ch = '0' + (n % 10);
            num = ch + num;
            n /= 10;
        }
        return countOne(0, num);
    }
    int countOne(int k, string& num)
    {
        if (k == num.size())
            return 0;

        int firstBit = num[k] - '0';
        int countFirst = 0, len = num.size() - k - 1;

        // 1)统计首位为1的次数
        if (firstBit > 1) countFirst = pow(10, len);
        else if (firstBit == 1) countFirst = (k + 1 == num.size()) ? 1 : stoi(num.substr(k + 1)) + 1;

        // 3)统计1出现在非首位的次数
        int countOthers = firstBit * len * pow(10, len - 1);

        // 4)k+1递归求解
        int countRecursive = countOne(k + 1, num);

        return countFirst + countOthers + countRecursive;
    }
};