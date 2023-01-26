// 剑指 Offer 20. 表示数值的字符串

/*
    诸字符判断
*/
class Solution {
public:
    bool isNumber(string s) {
        string str = excludeSpacing(s);
        int decimalPos = getDecimalPos(str);
        int ePos = getEPos(str);

        if (decimalPos >= 0)
        {
            if (ePos >= 0) return checkDecimal(str.substr(0, ePos)) && checkNumeric(str.substr(ePos + 1, str.size() - ePos));
            else return checkDecimal(str);
        }
        else
        {
            
            if (ePos >= 0) return checkNumeric(str.substr(0, ePos)) && checkNumeric(str.substr(ePos + 1, str.size() - ePos));
            else return checkNumeric(str);
        }

    }
    bool checkNumeric(const string& s)
    {
        if (s.empty()) return false;
        int i = (s[0] == '+' || s[0] == '-') ? 1 : 0;

        int cnt = 0;
        for (; i < s.size(); i++)
        {
            if (!(s[i] >= '0' && s[i] <= '9')) return false;
            cnt++;
        }
        if (cnt < 1) return false;
        return true;
    }
    bool checkDecimal(const string& s)
    {
        if (s.empty()) return false;
        int i = (s[0] == '+' || s[0] == '-') ? 1 : 0;
        int dotPos = getDecimalPos(s);
        int cnt = 0;
        for (; i < dotPos; i++)
        {
            if (!(s[i] >= '0' && s[i] <= '9')) return false;
            cnt++;
        }
        i++;
        for (;i < s.size(); i++)
        {
            if (!(s[i] >= '0' && s[i] <= '9')) return false;
            cnt++;
        }
        if (cnt < 1) return false;
        return true;
    }
    string excludeSpacing(string& s)
    {
        int i = 0, j = s.size() - 1, n = s.size();
        while (i < n && s[i] == ' ') i++;
        while (j >= 0 && s[j] == ' ') j--;
        if (i <= j) return s.substr(i, j - i + 1);
        return "";
    }
    
    int getDecimalPos(const string& s)
    {
        for (int i = 0; i < s.size(); i++)
            if (s[i] == '.') return i;
        return -1;
    }

    int getEPos(const string& s)
    {
        for (int i = 0; i < s.size(); i++)
            if (s[i] == 'e' || s[i] == 'E') return i;
        return -1;
    }
};