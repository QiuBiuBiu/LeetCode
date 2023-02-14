// 剑指 Offer 48. 最长不含重复字符的子字符串
// 请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度。


/*
    DP，T=O(n), S=O(1)
    用map记录字符s[i]上一次出现的index，记f[i]表示以字符s[i]结尾的无重复字符的最长子串，则有
        1）s[i]之前没有出现过 或者 上次出现在f[i-1]保存的字符之外，则f[i]=f[i-1]+1
        2) 否则，f[i]=i-map[s[i]]
    见leetcode第3题
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<int, int> mp;
        int res = 0, len = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (mp.find(s[i]) == mp.end() || mp[s[i]] + len < i) ++len;
            else
            {
                len = i - mp[s[i]];
            }
            mp[s[i]] = i;
            res = max(res, len);
        }
        return res;
    }
};