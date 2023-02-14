// 22. 括号生成
// 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。


/*
    1）递归回溯法（dfs），T=O(2^n)
    n的最大值取8，我们考虑用递归法思路解决，定义该问题为用n个左括号和n个右括号生成一个有效的括号组合
    用left和right记录还剩余可用的左括号和有括号的数目
*/

class Solution {
public:
    vector<string> res;
    vector<string> generateParenthesis(int n) {
        generate(n, n, "");
        return res;
    }
    void generate(int left, int right, string parenthesis)
    {
        if (left == 0 && right == 0)
        {
            res.emplace_back(parenthesis);
            return ;
        }
        if (left > 0) generate(left - 1, right, parenthesis + "("); // 左括号有剩余，用左括号
        if (right > left) generate(left, right - 1, parenthesis + ")"); // 有左括号未匹配，用右括号
    }
};

/*
    2）暴力法，T=O(n * 2^n)
    来自：https://leetcode.cn/problems/generate-parentheses/solutions/192912/gua-hao-sheng-cheng-by-leetcode-solution/
*/
class Solution {
    bool valid(const string& str) {  // 这里验证括号是否有效的办法相对第20题可以简化，因为只有'('和')'
        int balance = 0;
        for (char c : str) {
            if (c == '(') {
                ++balance;
            } else {
                --balance;
            }
            if (balance < 0) {
                return false;
            }
        }
        return balance == 0;
    }

    void generate_all(string& current, int n, vector<string>& result) {
        if (n == current.size()) {
            if (valid(current)) {
                result.push_back(current);
            }
            return;
        }
        current += '(';
        generate_all(current, n, result);
        current.pop_back();
        current += ')';
        generate_all(current, n, result);
        current.pop_back();
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current;
        generate_all(current, n * 2, result);
        return result;
    }
};