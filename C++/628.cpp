/*
思路：
    水题
*/
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        return fun(nums);
    }
    int fun(vector<int>& a) {
        sort(a.begin(), a.end());
        int n = a.size();
        int u = a[0] * a[1] * a[n - 1];
        int v = a[n - 1] * a[n - 2] * a[n - 3];
        return max(u, v);
    }
};