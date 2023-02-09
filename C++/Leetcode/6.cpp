/*
6. N 字形变换
    将一个给定字符串 s 根据给定的行数 numRows ，以从上往下、从左到右进行 Z 字形排列。
    比如输入字符串为 "PAYPALISHIRING" 行数为 3 时，排列如下：
    P   A   H   N
    A P L S I I G
    Y   I   R
    之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："PAHNAPLSIIGYIR"。

    输入：s = "PAYPALISHIRING", numRows = 4
    输出："PINALSIGYAHRPI"
    解释：
    P     I    N
    A   L S  I G
    Y A   H R
    P     I
*/


/*
    模拟，T=O(n)，n = s.size()
    用一个字符串数组str[N]来记录每行最终要记录的字符串，用指针i来模拟N字形的变换填充str[i]。
    最终结果即str中每一行的字符串的拼接。
*/
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        int n = s.size(), N = min(numRows, n);
        string str[N];
        int i = 0, flag = 0;
        for (const auto& ch : s)
        {
            str[i] += ch;
            if (i == numRows - 1) flag = 1;
            if (i == 0) flag = 0;
            i += flag ? -1 : 1;
        }
        string res;
        for (const auto& ss : str)
            res += ss;
        return res;
    }
};