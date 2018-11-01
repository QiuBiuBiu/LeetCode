/*
思路：
    经典的回溯法
*/
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
        perm(nums, 0, nums.size() - 1);
        return res;
    }
    void perm(vector<int>& a, int s, int e) {
        if (s == e) {
            res.push_back(a);
            return ;
        }
        for (int i = s; i <= e; i++) {
            swap(a[i], a[s]);
            perm(a, s + 1, e);
            swap(a[i], a[s]);
        }
    }
};