/*
122. 买卖股票的最佳时机 II
    给你一个整数数组 prices ，其中 prices[i] 表示某支股票第 i 天的价格。
    在每一天，你可以决定是否购买和/或出售股票。你在任何时候 最多 只能持有 一股 股票。你也可以先购买，然后在 同一天 出售。
    返回 你能获得的 最大 利润 。

    输入：prices = [7,1,5,3,6,4]
    输出：7
    解释：在第 2 天（股票价格 = 1）的时候买入，在第 3 天（股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5 - 1 = 4 。
        随后，在第 4 天（股票价格 = 3）的时候买入，在第 5 天（股票价格 = 6）的时候卖出, 这笔交易所能获得利润 = 6 - 3 = 3 。
        总利润为 4 + 3 = 7 。
*/


/*
    动态规划+贪心，T=O(n), S=O(1)
    preMax记录从上次卖出之后买进然后今天卖出能取得的最大收益。
    因为可以无限次交易，所以每当卖出能取得收益时，就卖掉股票。
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int preMax = 0, res = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            preMax = max(prices[i] - prices[i - 1] + preMax, prices[i] - prices[i - 1]);
            if (preMax > 0)
            {
                res += preMax; // 卖掉股票，总收入累加
                preMax = 0; // preMax置零
            }
        }
        return res;
    }
};