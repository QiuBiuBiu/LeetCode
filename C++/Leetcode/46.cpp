// 46. 全排列
// 给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。


/*
    1）回溯法，T=O(n*n!)
*/
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
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
        for (int i = k; i < nums.size(); i++)
        {
            swap(nums[k], nums[i]);
            dfs(nums, k + 1);
            swap(nums[k], nums[i]);
        }
    }
};


/*
    2）dfs + 回溯，T=O(n*n!)
*/
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
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
        for (int i = 0; i < nums.size(); i++)  // 每次从0开始枚举
        {
            if (vis[i] == 0) // 需要借助vis数组来判断是否该数字被取过
            {
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
    3）迭代法1，插空
    首先对于一个数字的序列，假如是1。那么序列{1}即为它的全排列。
    那么，对于多个数字的序列，假如是1, 2, 3. 我们首先初始化序列{1}。
    对于数字2而言，它可以插入在初始化序列的第0个位置，即{2, 1}；也可以插入在第二个位置，即{1, 2}。
    对于数字3，上面两个序列，每个序列共有3个位置可以插入，于是最终可以生成6种序列，即为所求。
*/
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ress;
        ress.emplace_back(vector<int>{nums[0]}); // 用第一个数字来初始化
        for (int i = 1; i < nums.size(); ++i) // 对后面的每一个数字，我们进行插空
        {
            vector<vector<int>> tmps;
            for (int k = 0; k <= i; ++k) // 枚举插空的位置
            {
                for (const auto& res : ress)
                {
                    vector<int> tmp = res;
                    tmp.insert(tmp.begin() + k, nums[i]); // 插空
                    tmps.emplace_back(tmp);
                }
            }
            ress = tmps;
        }
        return ress;
    }
};

/*
    4）迭代法2，插空，对方法3的空间复杂度进一步优化
*/
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res(1); // 初始化
        vector<int> tmp;
        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = res.size() - 1; j >= 0; --j) // 从后之前对序列插空，节省了上面tmps的空间消耗
            {
                for (int k = 0; k < i; ++k) // 拷贝res[j]为tmp，并对它的前i-1个位置插空，并将结果放入结果集res
                {
                    tmp = res[j];
                    tmp.insert(tmp.begin() + k, nums[i]);
                    res.emplace_back(tmp);
                }
                res[j].emplace_back(nums[i]); // 关键一步，直接对res[j]操作，将num[i]插入最后一个位置i，即res[j]的尾端
            }
        }
        return res;
    }
};