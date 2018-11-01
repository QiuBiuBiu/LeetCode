/*
思路：
    31题衍生，注意先排序就好
*/
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        do {
            res.push_back(nums);
        } while(perm(nums));
        return res;
    }
    int perm(vector<int>& a) {
        int n = a.size(), i = n - 1, k = n - 1;
        while (i > 0 && a[i - 1] >= a[i])
            i--;
        if (i > 0) {
            while (k >= i && a[i - 1] >= a[k])
                k--;
            swap(a[i - 1], a[k]);
            reverse(a.begin() + i, a.end());
            return 1;
        }
        return 0;
    }
};