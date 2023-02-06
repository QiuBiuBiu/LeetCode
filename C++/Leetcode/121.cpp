/*
121. 买卖股票的最佳时机
    给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。
    你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。
    返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。

    输入：[7,1,5,3,6,4]
    输出：5
    解释：在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
        注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格；同时，你不能在买入前卖出股票。
*/

/*
    1）动态规划，T=O(n), S=O(1)
    preMax记录前一天卖股票能取得的最大收益，那么当天我卖股票能取得的最大收益是下面两个的最大值：
        1）在前一天买的基础上，我前一天不卖，转到今天卖
        2）前天买进，今天卖出
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int preMax = 0, res = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            preMax = max(prices[i] - prices[i - 1] + preMax, prices[i] - prices[i - 1]);
            res = max(res, preMax);
        }
        if (res >= 0) return res;
        return 0;
    }
};

/*
    2）动态规划，T=O(n), S=O(1)
    既然卖的日子固定，那么当天能取得的股票最大收益是在这之前最便宜的时候买；
    因此维护一个股票的最低价Min，用来更新今天的最大收益。
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int Min = prices[0], res = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            res = max(res, prices[i] - Min);
            Min = min(Min, prices[i]);
        }
        if (res >= 0) return res;
        return 0;
    }
};