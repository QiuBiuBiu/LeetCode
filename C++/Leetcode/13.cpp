/*
思路：
    从后往前，若前面的value小于后面的value,那么则需要减去当前值（eg:IV）
    反之，则需加上当前值。

    当然一开始的思路是“大模拟”……
*/
class Solution {
public:
    int romanToInt(string s) {
        map <char, int> T = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        int n = s.size(), ans = T[ s[n - 1] ];
        for (int i = n - 2; i >= 0; i--) {
            if (T[ s[i] ] >= T[ s[i + 1] ])
                ans += T[ s[i] ];
            else
                ans -= T[ s[i] ];
        }
        return ans;
    }
};

// 大模拟都不忍心贴出来……
class Solution {
public:
    int romanToInt(string s) {
        int n = s.size(), ans = 0, flag = 1;
        for (int i = n - 1; i >= 0; i--) {
            while(flag && s[i] == 'I') {
                ans++;
                i--;
            }
            flag = 0;
            
            if (i - 1 >= 0) {
                if (s[i] == 'V') {
                    if (s[i - 1] == 'I') {
                        ans += 4;
                        i--;
                    }
                    else
                        ans += 5;
                }
                else if (s[i] == 'X') {
                    if (s[i - 1] == 'I') {
                        ans += 9;
                        i--;
                    }
                    else
                        ans += 10;
                }
                else if (s[i] == 'L') {
                    if (s[i - 1] == 'X') {
                        ans += 40;
                        i--;
                    }
                    else
                        ans += 50;
                }
                else if (s[i] == 'C') {
                    if (s[i - 1] == 'X') {
                        ans += 90;
                        i--;
                    }
                    else
                        ans += 100;
                }
                else if (s[i] == 'D') {
                    if (s[i - 1] == 'C') {
                        ans += 400;
                        i--;
                    }
                    else
                        ans += 500;
                }
                else {
                    if (s[i - 1] == 'C') {
                        ans += 900;
                        i--;
                    }
                    else
                        ans += 1000;
                }
            }
            else {
                if (s[i] == 'V') ans += 5;
                if (s[i] == 'X') ans += 10;
                if (s[i] == 'L') ans += 50;
                if (s[i] == 'C') ans += 100;
                if (s[i] == 'D') ans += 500;
                if (s[i] == 'M') ans += 1000;
            }
        }
        return ans;
    }
};