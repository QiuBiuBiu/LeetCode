class Solution {
public:
    int numSquares(int n) {
        static vector<int> f(1, 0);  // leetcode打表
        while (f.size() <= n) {
            int m = f.size(), Min = INT_MAX;
            for (int i = 1; i * i <= m; i++)
                Min = min(Min, f[m - i * i] + 1);
            f.push_back(Min);
        }
        return f[n];
    }
};