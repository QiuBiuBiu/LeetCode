/*
思路：
    滑动窗口
    即维护一个i到j连续的累乘p，直到p值大于等于k时，则一定可以说明i到j-1的累乘是小于p的。
    则此时我们移除a[i]，继续检验p是否小于k而“不用将p值归1”（这一步大大减少了时间复杂度）
    同时移除a[i]使我们可以得到j-i个小于k的连续累乘字串。
*/
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>& a = nums;
        int p = 1, ans = 0, i = 0, j = 0;
        while (j < n) {
            if (p * a[j] >= k) {
                if(i == j) { // 当前a[i]的值都大于k，i和j一起后移
                    i++;
                    j++;
                    p = 1;
                }
                else {
                    ans += j-i;
                    p /= a[i];
                    i++;
                }
            }
            else {
                p *= a[j];
                j++;
            }
        }
        while (i < j) { // i<j 说明最后一段连续的字串的累乘都小于k
            ans += j-i;
            i++;
        }
        return ans;
    }
};