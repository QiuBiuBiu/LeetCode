class Solution:
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        lens, ans, ansl = len(s), '', 0
        for i in range(lens):
            for j in range(i + 1, lens + 1):
                if self.check(s[i:j], j - i) and ansl < j - i:
                    ans = s[i:j]
                    ansl = j - i
        return ans

    def check(self, s, lens):
        i, j = 0, lens - 1
        while i < j:
            if s[i] != s[j]:
                return 0
            i, j = i + 1, j - 1
        return 1


if __name__ == '__main__':
    print(Solution().longestPalindrome("babad"))