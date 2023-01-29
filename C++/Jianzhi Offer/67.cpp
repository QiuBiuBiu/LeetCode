// 面试题67. 把字符串转换成整数

/*
    逐字符判断，T=O(n)
*/
class Solution {
public:
    int strToInt(string str) {
        int n = str.size(), i = 0;
        while (i < n && str[i] == ' ') i++; // 去除前置空格
        if (i == n) return 0;
        if (str[i] == '+' || str[i] == '-') // 有符号数
        {
            char ch = str[i++];
            if (i == n || !(str[i] >= '0' && str[i] <= '9')) return 0;
            return ch == '-' ? getNum(str.substr(i), true) : getNum(str.substr(i), false);
        }
        else if (str[i] >= '0' && str[i] <= '9') return getNum(str.substr(i), false);
        else return 0;
    }
    int getNum(string str, bool isNagtive)
    {
        long long num = 0;
        int i = 0;
        while (i < str.size() && (str[i] >= '0' && str[i] <= '9'))
        {
            num = num * 10 + (str[i] - '0');
            if (!isNagtive && num > pow(2, 31) - 1) return pow(2, 31) - 1;
            else if (isNagtive && -num < pow(-2, 31)) return pow(-2, 31);
            i++;
        }
        return isNagtive ? static_cast<int>(-num) : static_cast<int>(num);
    }
};