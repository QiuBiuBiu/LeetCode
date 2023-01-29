// 剑指 Offer 17. 打印从1到最大的n位数

/*
    1）直接打印
*/

class Solution {
public:
    vector<int> printNumbers(int n) {
        int m = pow(10, n) - 1;
        vector<int> res(m);
        for (int i = 0; i < m; i++)
            res[i] = i + 1;
        return res;
    }
};

/*
    2）全排列法
    // Todo
*/