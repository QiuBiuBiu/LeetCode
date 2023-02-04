/*
322. 零钱兑换
    给你一个整数数组 coins ，表示不同面额的硬币；以及一个整数 amount ，表示总金额。
    计算并返回可以凑成总金额所需的 最少的硬币个数 。如果没有任何一种硬币组合能组成总金额，返回 -1 。
    你可以认为每种硬币的数量是无限的。
*/

/*
    动态规划，T=O(n^2)，S=O(n)
    记dp[k]为凑齐k块钱最小需要几个硬币，
    初始化dp[0]=0；其他为MAX，即不能凑齐。
*/
class Solution {
public:
    const int MAX = 0x7f7f7f7f;
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, MAX);
        dp[0] = 0;
        for (int i = 0; i <= amount; i++)
        {
            for (int j = 0; j < coins.size(); j++)
            {
                int coin = coins[j];
                
                if (i - coin >= 0 && dp[i - coin] != MAX)
                {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        if (dp[amount] == MAX) return -1;
        return dp[amount];
    }
};

/*
    注意此题不能用贪心法，因为我们要保证凑齐总金额，而每次使用最大面额的硬币并不能保证最后能凑齐。
*/