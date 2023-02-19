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
    2）回溯法，T=O(n*n!)
    用一个unordered_set来去重
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

/*
    3）回溯法，T=O(n*n!)
    用一个unordered_set来去重
*/
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> vis(nums.size(), 0);
        vector<int> path;
        dfs(nums, 0, path, vis);
        return res;
    }
    void dfs(vector<int>& nums, int cnt, vector<int>& path, vector<int>& vis)
    {
        if (cnt == nums.size())
        {
            res.emplace_back(path);
            return ;
        }
        unordered_set<int> st;
        for (int i = 0; i < nums.size(); i++) 
        {
            if (vis[i]) continue;
            if (st.find(nums[i]) == st.end()) // 用一个unordered_set来去重
            {
                st.insert(nums[i]);
                vis[i] = 1;
                path.emplace_back(nums[i]);
                dfs(nums, cnt + 1, path, vis);
                path.pop_back();
                vis[i] = 0;
            }  
        }
    }
};


/*
    3）回溯法，T=O(n*n!)
    排序后借助vis数组来去重
*/
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // 先排序
        vector<int> vis(nums.size(), 0);
        vector<int> path;
        dfs(nums, 0, path, vis);
        return res;
    }
    void dfs(vector<int>& nums, int cnt, vector<int>& path, vector<int>& vis)
    {
        if (cnt == nums.size())
        {
            res.emplace_back(path);
            return ;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (vis[i]) continue;
            if (i > 0 && nums[i] == nums[i - 1] && vis[i - 1] == 0) // 去重
                continue;

            vis[i] = 1;
            path.emplace_back(nums[i]);
            dfs(nums, cnt + 1, path, vis);
            path.pop_back();
            vis[i] = 0;
        }
    }
};