/*
思路：
    贪心
*/
class Solution {
public:
    string intToRoman(int num) {
        string symbol[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        int value[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string ans = "";
        int k = 0;
        while (num) {
            if (num - value[k] >= 0) {
                num -= value[k];
                ans += symbol[k];
            }
            else
                k++;
            
        }
        return ans;
    }
};