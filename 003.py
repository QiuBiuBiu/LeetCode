class Solution:
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        d, i, ans = {}, 0, 0
        for j in range(len(s)):
            if s[j] in d:
                i = d[s[j]] + 1
            d[s[j]] = j
            ans = max(ans, j - i + 1)
        return ans


if __name__ == '__main__':
    print(Solution().lengthOfLongestSubstring("abcabcbb"))
    print(Solution().lengthOfLongestSubstring("pwwkew"))
    print(Solution().lengthOfLongestSubstring("aaaaaa"))