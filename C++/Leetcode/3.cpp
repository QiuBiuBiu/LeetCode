/*
3. 无重复字符的最长子串
    给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。

    输入: s = "abcabcbb"
    输出: 3 
    解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
*/


/*
    动态规划，T=O(n), S=O(1)
    用map记录字符s[i]上一次出现的index，记f[i]表示以字符s[i]结尾的无重复字符的最长子串，则有
        1）s[i]之前没有出现过 或者 上次出现在f[i-1]保存的字符之外，则f[i]=f[i-1]+1
        2) 否则，f[i]=i-map[s[i]]
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