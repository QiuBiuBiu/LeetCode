/*
5. 替换空格
    请实现一个函数，把字符串 s 中的每个空格替换成"%20"。

    输入：s = "We are happy."
    输出："We%20are%20happy."
*/

/*
    1）从后往前+原地修改，T=O(n)，S=O(1)
*/
class Solution {
public:
    string replaceSpace(string s) {

        int spaceCnt = 0, n = s.size();
        for (const auto& ch : s)
        {
            if (ch == ' ') ++spaceCnt;
        }

        // 修改s的长度
        s.resize(spaceCnt * 2 + n); // 注意是*2而不是*3
        for (int i = s.size() - 1, j = n - 1; i >= 0 && j >= 0; j--)
        {
            if (s[j] == ' ') 
            {
                s[i--] = '0';
                s[i--] = '2';
                s[i--] = '%';
            }
            else s[i--] = s[j];
        }
        return s;
    }
};