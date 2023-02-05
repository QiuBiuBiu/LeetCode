/*
673. 最长递增子序列的个数
    给定一个未排序的整数数组 nums ， 返回最长递增子序列的个数 。
    注意 这个数列必须是 严格 递增的。

    输入: [1,3,5,4,7]
    输出: 2
    解释: 有两个最长递增子序列，分别是 [1, 3, 4, 7] 和[1, 3, 5, 7]。
*/

/*
    动态规划，LIS(最长递增子序列)系列问题，T=O(n^2), S=O(n)
    PS: LIS基础问题请看第300题
    在LIS的基础上，需要添加一个cnt数组来保存更新到此状态的种类数。
*/
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size(), MAX = 1;
        vector<int> f(n, 1);
        vector<int> cnt(n, 1); // 初始为1，即最少状态是由我自己本身更新来的
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                {
                    if (f[j] + 1 > f[i]) // i的状态是由j更新来的，所以种类数等于cnt[j]
                    {
                        f[i] = f[j] + 1;
                        cnt[i] = cnt[j]; 
                    }
                    else if (f[j] + 1 == f[i]) // i的状态可能由不同的j更新，此种情况需要把他们都记录下来
                    {
                        cnt[i] += cnt[j]; 
                    }
                }
            }
            MAX = max(MAX, f[i]);
        }
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            if (f[i] == MAX) res += cnt[i];
        }
        return res;
    }
};