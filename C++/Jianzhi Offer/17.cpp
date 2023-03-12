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
    2）dfs，全排列
    当n很大时，我们需要用string模拟数字。然后dfs来全排列
*/
class Solution {
public:
    vector<int> res;
    vector<int> printNumbers(int n) {
        dfs("", 0, n);
        return res;
    }
    void dfs(string num, int k, int n)
    {
        if (k == n)
        {
            int number = stoi(num);
            if (number) res.emplace_back(number);
            return ;
        }
        for (int i = 0; i < 10; ++i)
        {
            dfs(num + to_string(i), k + 1, n);
        }
    }
};