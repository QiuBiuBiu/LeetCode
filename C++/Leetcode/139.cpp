// 139. 单词拆分
// 给你一个字符串 s 和一个字符串列表 wordDict 作为字典。请你判断是否可以利用字典中出现的单词拼接出 s 。
// 注意：不要求字典中出现的单词全部都使用，并且字典中的单词可以重复使用。


/*
    动态规划，T=O(n^2), S=O(n)
*/
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> f(s.size() + 1, 0);
        return dp(s, wordDict, f, s.size());
    }
    bool dp(string& s, vector<string>& wordDict, vector<int>& f, int n)
    {
        if (n == 0) return true;
        if (f[n]) return f[n] > 0 ? true : false;

        for (int i = 0; i < wordDict.size(); i++)
        {
            int len = wordDict[i].size();

            if (len <= n && wordDict[i] == s.substr(n - len, len))
            {
                if (dp(s, wordDict, f, n - wordDict[i].size())) return true;
            }
        }
        f[n] = -1;
        return false;
    }
};

// Todo 140. 单词拆分 II