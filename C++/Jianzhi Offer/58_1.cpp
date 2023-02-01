// 剑指 Offer 58 - I. 翻转单词顺序

/*
    1）遍历+stack，T=O(n)，S=O(n)
*/
class Solution {
public:
    string reverseWords(string s) {
        stack<string> sk;
        string str = "";
        for (auto ch : s)
        {
            if (ch == ' ')
            {
                if (str != "") sk.push(str);
                str = "";
            }
            else str += ch;
        }
        if (str != "") sk.push(str);
        
        if (sk.empty()) return "";
        string res = sk.top();
        sk.pop();
        while (!sk.empty())
        {
            res += " ";
            res += sk.top();
            sk.pop();
        }
        return res;
    }
};

/*
    2）原地修改，请看leetcode 151.cpp
*/