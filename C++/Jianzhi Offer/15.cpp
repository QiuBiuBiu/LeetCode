// 剑指 Offer 15. 二进制中1的个数

// 1）逐位判断, T=O(logn)
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        while (n)
        {
            if (n % 2) cnt++; // 或者使用 if(n & 1) cnt++;
            n /= 2; // 或者 n >>= 1;
        }
        return cnt;
    }
};

// 2）n&(n-1), T=O(M), M为数字n的二进制中1的位数
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        while (n)
        {
            n = n & (n - 1); // 若n为12，二进制n为1100，二进制n-1为1011
            cnt++;
        }
        return cnt;
    }
};