class Solution {
public:
    vector<string> res{};
    vector<string> numToChar{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> letterCombinations(string digits) {
        if (digits.size())
            backTracking(digits, "", digits.size(), 0);
        return res;
    }
    void backTracking(string str, string ans, int n, int k) {
        if (k == n) {
            res.push_back(ans);
            return ;
        }
        int num = str[k] - '0';
        for (int i = 0; i < numToChar[num].length(); i++) {
            backTracking(str, ans + numToChar[num][i], n, k + 1);
        }
    }
    
};