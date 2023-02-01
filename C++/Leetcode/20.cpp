class Solution {
public:
    bool isValid(string s) {
        stack<char> sk;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                sk.push(s[i]);
            }
            else {
                if (!sk.empty()) {
                    char a = sk.top();
                    char b = s[i];
                    sk.pop();
                    if (!((a == '(' && b == ')') || (a == '[' && b == ']') || (a == '{' && b == '}')))
                        return false;                    
                }
                else
                    return false;
            }
        }
        if (sk.empty())
            return true;
        return false;
    }
};