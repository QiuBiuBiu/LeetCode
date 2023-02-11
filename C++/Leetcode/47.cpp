// 47. 全排列 II
// 给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。


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

/*
    2）用一个unordered_set来去重
*/
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        dfs(nums, 0);
        return res;
    }
    void dfs(vector<int>& nums, int k)
    {
        if (k == nums.size())
        {
            res.emplace_back(nums);
            return ;
        }
        unordered_set<int> st;
        for (int i = k; i < nums.size(); i++)
        {
            if (st.find(nums[i]) == st.end())
            {
                swap(nums[k], nums[i]);
                dfs(nums, k + 1);
                swap(nums[k], nums[i]);                
            }
            st.insert(nums[i]);
        }
    }
};