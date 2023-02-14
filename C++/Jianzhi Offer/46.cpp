// 剑指 Offer 46. 把数字翻译成字符串
// 给定一个数字，我们按照如下规则把它翻译为字符串：0 翻译成 “a” ，1 翻译成 “b”，……，11 翻译成 “l”，……，25 翻译成 “z”。一个数字可能有多个翻译。请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法。


/*
    DP，T=O(n), S=O(n)
    定义dp[i]为从i打头至尾端的字符串有多少种翻译的方法，则：
    1) 若num[i]和num[i+1]不能组合，那么f[i] = f[i+1]
    2）若num[i]和num[i+1]能组合，那么f[i] = f[i+1] + f[i+2]
    初始化f[i] = 1
*/
class Solution {
public:
    int translateNum(int num) {
        auto f = to_string(num); // 利用to_string将数字转换为字符串
        int n = f.size();
        vector<int> dp(n + 1, 1);
        for (int i = n - 2; i >= 0; i--)
        {
            // 注意要排除‘0’的情况，因为‘0’和后面一个字符组合在本题中无意义
            if (f[i] != '0' && (f[i] - '0') * 10 + (f[i + 1] - '0') < 26) dp[i] = dp[i + 1] + dp[i + 2];
            else dp[i] = dp[i + 1];
        }
        return dp[0];
    }
};