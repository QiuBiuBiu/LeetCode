// 剑指 Offer 66. 构建乘积数组

/*
    1）乘积数组
    具体请看：https://leetcode.cn/problems/gou-jian-cheng-ji-shu-zu-lcof/solutions/208840/mian-shi-ti-66-gou-jian-cheng-ji-shu-zu-biao-ge-fe/
*/

class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int n = a.size();
        if (n == 0) return vector<int>{};
        vector<int> b(n, 1);
        for (int i = 1; i < n; i++)
            b[i] = b[i - 1] * a[i - 1];
        int tmp = 1;
        for (int i = n - 2; i >= 0; i--)
        {
            tmp = tmp * a[i + 1];
            b[i] = b[i] * tmp;
        }
        return b;
    }
};

/*
    2）动态规划
    dp_left[i]记录i左侧的累乘和，dp_right[i]记录i右侧的累乘和
    故res[i] = dp_left[i] * dp_right[i]
*/
class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int n = a.size();
        if (n == 0) return vector<int>{};
        vector<int> res(n, 1), dp_left(n, 1), dp_right(n, 1);
        for (int i = 1; i < n; i++)
            dp_left[i] = dp_left[i - 1] * a[i - 1];
        for (int i = n - 2; i >= 0; i--)
            dp_right[i] = dp_right[i + 1] * a[i + 1];
        for (int i = 0; i < n; i ++)
            res[i] = dp_left[i] * dp_right[i];
        return res;
    }
};
