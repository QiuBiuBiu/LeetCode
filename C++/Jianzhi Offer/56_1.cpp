// 剑指 Offer 56 - I. 数组中数字出现的次数

/*
    位运算，异或
    n ^ 0 = n
    n ^ n = 0
    n ^ m = m ^ n
    (n ^ m) ^ n = m
*/

class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int n = 0;
        for (auto num : nums) // 1) 对所有数字异或，得到不相等的两个数的异或值n^m，记为n
            n ^= num;
            
        int x = 1;
        while ((x & n) == 0) // 注意这里的逻辑判断必须加括号，不然==的优先级要高于&
            x = x << 1; // 2）找到n^m的最右边不为0的位，记为x（x要么是n中的某位，要么是m中的某位）

        int a = n, b = n;
        for (auto num : nums)
        {
            if (num & x) a ^= num; // 3）按照与x相与的结果把数组分为两块，由于异或的性质那么不相等的两个数一定被分到了不同的块里
            else b ^= num; // 4）用n(即n^m)的值与每个块的数字相异或，由于(n^m)^n = m，所以我们最终能得到这两个数
        }
        return vector<int> {a, b};
    }
};