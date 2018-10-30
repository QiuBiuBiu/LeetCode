/*
思路：
    二维的回溯法，用l和r记录还剩余可用的左括号和有括号的数目
*/

class Solution {
public:
    vector<string> res;
    vector<string> generateParenthesis(int n) {
        backTracking(n, n, "");
        return res;
    }
    void backTracking(int l, int r, string ans) {
        if (l == 0 && r == 0) {
            res.push_back(ans);
            return ;
        }
        if (l > 0)
            backTracking(l - 1, r, ans + '(');
        if (r > 0 && r > l)
            backTracking(l, r - 1, ans + ')');
    }
};