// 剑指 Offer 56 - II. 数组中数字出现的次数 II

/*
    位运算，T=O(n*32)
    如果我们把所有出现三次的数字的二进制表示的每一位都分别加起来，那么每一位的和都能被3整除，我们利用这个性质来求解
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> bit(32, 0); // 统计所有位上1的个数
        for (auto& num : nums)
        {
            for (int j = 0; j < 32; j++)
            {
                if (num)
                {
                    if (num & 1) bit[j]++;
                }
                else break;

                num >>= 1;
            }
        }

        int res = 0;
        for (int j = 31; j >= 0; j--)
        {
            res <<= 1;
            res += (bit[j] % 3) ? 1 : 0; // 如果某一位1的个数不是3的倍数，说明 只出现一次的数字 在这一位上产生了1
        }
        return res;
    }
};