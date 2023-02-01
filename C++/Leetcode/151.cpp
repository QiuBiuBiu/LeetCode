/*
151. 反转字符串中的单词
    给你一个字符串 s ，请你反转字符串中 单词 的顺序。
    单词 是由非空格字符组成的字符串。s 中使用至少一个空格将字符串中的 单词 分隔开。
    返回 单词 顺序颠倒且 单词 之间用单个空格连接的结果字符串。

    注意：输入字符串 s中可能会存在前导空格、尾随空格或者单词间的多个空格。
    返回的结果字符串中，单词间应当仅用单个空格分隔，且不包含任何额外的空格。

    输入：s = "the sky is blue"
    输出："blue is sky the"
*/

/*
    1）遍历，T=O(n)，S=O(n)
    利用istringstream读入字符串吞掉空格，再利用stack反转字符串
*/
class Solution {
public:
    string reverseWords(string s) {
        istringstream ss(s);
        string str;
        stack<string> sk;
        while (ss >> str) sk.push(str);

        string res = sk.top();
        sk.pop();
        while (!sk.empty())
        {
            res += (" " + sk.top());
            sk.pop();
        }
        return res;
    }
};

/*
    2）两次reserve+原地修改，T=O(n)，S=O(1)
*/
class Solution {
public:
    string reverseWords(string s) {
        int i = 0, j = 0, n = s.size();
        while (j < n) // 将有效字符移至字符串前端
        {
            while (j < n && s[j] == ' ') j++;
            if (j == n) break;
            while (i < n && j < n && s[j] != ' ')
            {
                s[i++] = s[j++];
            }
            s[i++] = ' ';
        }
        s.resize(i - 1); // 修改s的长度
        _reverse(s, 0, s.size() - 1); // 对整个s进行反转
        int k = 0;
        while (k < s.size())
        {
            int pos = k, len = 0;
            while (k < s.size() && s[k] != ' ') ++k, ++len; // 再对每个小str进行反转
            _reverse(s, pos, pos + len - 1);
            ++k;
        }
        return s;
    }
    void _reverse(string& s, int i, int j)
    {
        for(int p = i, q = j; p < q; p++, q--)
        {
            swap(s[p], s[q]);
        }
    }
};