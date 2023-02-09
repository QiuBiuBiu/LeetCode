/*
7. 整数反转
    给你一个 32 位的有符号整数 x ，返回将 x 中的数字部分反转后的结果。
    如果反转后整数超过 32 位的有符号整数的范围 [−231,  231 − 1] ，就返回 0。
    假设环境不允许存储 64 位整数（有符号或无符号）。

    输入：x = 123
    输出：321
*/

/*
    因为题目不允许存储64位整数，故不可使用long long类型。
    在计算结果中间加判断逻辑即可。
*/
class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        while (x)
        {
            int t = x % 10;
            if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && t > 7)) // 大于最大
                return 0;
            if (ans < INT_MIN / 10 || (ans == INT_MIN / 10 && t < -8)) // 小于最小
                return 0;
            ans = ans * 10 + t;
            x /= 10;
        }
        return ans;
    }
};