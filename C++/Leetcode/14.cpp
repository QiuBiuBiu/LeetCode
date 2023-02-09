/*
14. 最长公共前缀
    编写一个函数来查找字符串数组中的最长公共前缀。
    如果不存在公共前缀，返回空字符串 ""。

    输入：strs = ["flower","flow","flight"]
    输出："fl"
*/


/*
    遍历判断，T=O(nm)，m为每个字符串的长度，S=O(1)
*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string str = strs[0];
        for (int i = 0; i < strs[0].size(); i++)
        {
            char ch = str[i];
            for (int j = 1; j < strs.size(); j++)
            {
                if (i >= strs[j].size() || strs[j][i] != ch)
                {
                    return str.substr(0, i);
                }
            }
        }
        return str;
    }
};