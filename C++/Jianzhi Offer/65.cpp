// 剑指 Offer 65. 不用加减乘除做加法

class Solution {
public:
    int add(int a, int b) {
        do {
            int sum = a ^ b;  // 异或运算记录当前位的加法运算

            // 负数的左移可能会导致error: left shift of negative value
            // 或者使用((a & b) & 0x7fffffff) << 1;保证carry的首位一定为1
            // 详情请看: https://leetcode.com/problems/sum-of-two-integers/solutions/302977/C++:-the-evil-runtime-error:-left-shift-of-negative-value-reason-and-how-to-solve/
            int carry = static_cast<unsigned int>(a & b) << 1;  // 与运算记录进位

            a = sum;
            b = carry;

        } while(b);

        return a;
    }
};