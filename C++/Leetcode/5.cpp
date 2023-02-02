/*
5. 最长回文子串
    给你一个字符串 s，找到 s 中最长的回文子串。
    如果字符串的反序与原始字符串相同，则该字符串称为回文字符串。

    输入：s = "babad"
    输出："bab"
    解释："aba" 同样是符合题意的答案。
*/


/*
    1）双指针，T=O(n)，S=O(1)
    枚举回文串可能出现的index，然后利用双指针由中心向外扩散找可能的最大值
*/
class Solution {
public:
    string longestPalindrome(string s) {
        int maxLen = 0, maxIndex = 0;
        for (int i = 0; i < s.size(); i++)
        {
            int len = getLen(i, s.size(), s);
            if (maxLen < len)
            {
                maxLen = len;
                maxIndex = i - (len - 1) / 2;
            }
        }
        return s.substr(maxIndex, maxLen);
    }
    int getLen(int k, int n, string& s)
    {
        int len = 1;
        int i = k - 1, j = k + 1; // 以k为中心，扩散查找回文串长度为奇数的情况
        for (; i >= 0 && j < n; i--, j++)
        {
            if (s[i] != s[j])
            {
                len = max(len, j - i - 1); 
                break;
            }
        }
        if (i == - 1 || j == n) 
            len = max(len, j - i - 1);

        i = k, j = k + 1; // 以k，k+1为中心，扩散查找回文串长度为偶数的情况
        for (; i >= 0 && j < n; i--, j++)
        {
            if (s[i] != s[j])
            {
                len = max(len, j - i - 1);
                break;
            }
        }
        if (i == - 1 || j == n) 
            len = max(len, j - i - 1);
        return len;
    }
};

/*
    2）动态规划，T=O(n)，S=O(n^2)
    记dp[i][j]为i到j的子串是否为回文串，则必有dp[i][i]=1；
    又当s[i]和s[j]相等时，且满足以下任意条件：
        a) i = j - 1
        b) dp[i+1][j-1] = 1
    则有dp[i]][j] = 1;
*/
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = 0; i < n; i++) 
            dp[i][i] = 1;
        int maxLen = 1, maxIndex = 0;
        for (int i = n; i >= 0; i--)
        {
            for (int j = i + 1; j < n; j++)
            {
                
                if (s[i] == s[j] && (i + 1 < n && j - 1 >= 0 && dp[i + 1][j - 1] || i == j - 1)) 
                {
                    dp[i][j] = 1;
                    if (maxLen < j - i + 1)
                    {
                        maxLen = j - i + 1;
                        maxIndex = i;
                    }
                }
            }
        }
        return s.substr(maxIndex, maxLen);
    }
};