// 剑指 Offer 63. 股票的最大利润
// 假设把某股票的价格按照时间先后顺序存储在数组中，请问买卖该股票一次可能获得的最大利润是多少？


/*
    DP，T=O(n), S=O(1)
    见leetcode 121题
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) return 0;
        int Min = prices[0], res = 0;
        for (auto p : prices)
        {
            Min = min(Min, p);
            res = max(res, p - Min);
        }
        return res;
    }
};