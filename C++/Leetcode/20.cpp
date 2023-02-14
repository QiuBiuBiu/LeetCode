// 20. 有效的括号
// 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。


/*
    辅助栈，T=O(n)，S=O(n)
*/
class Solution {
public:
    bool isValid(string s) {
        map<char, char> mp;
        mp['('] = ')', mp['['] = ']', mp['{'] = '}';
        stack<char> sk;
        for (const auto & ch : s)
        {
            if (ch == '(' || ch == '[' || ch == '{') 
            {
                sk.push(mp[ch]); // 存储对应的右括号
            }
            else
            {
                if (!sk.empty() && sk.top() == ch)
                {
                    sk.pop();
                }
                else return false;
            }
        }
        return sk.empty();
    }
};