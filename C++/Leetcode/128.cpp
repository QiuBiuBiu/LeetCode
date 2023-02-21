// 128. 最长连续序列
// 给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。


/*
    1）动态规划，T=O(n)，S=O(n)
    mp[i]记录以i结尾的数字的最长序列，则mp[i]=1+mp[i-1]
*/
class Solution {
public:
    unordered_map<int, int> mp;
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        for (const auto& a : nums)
        {
            mp[a] = 0;
        }
        for (const auto& a : nums)
        {
            res = max(res, dp(a));
        }
        return res;
    }
    int dp(int num)
    {
        if (mp.find(num) == mp.end()) return 0;
        if (mp[num]) return mp[num];

        mp[num] = 1 + dp(num - 1);
        return mp[num];
    }
};


/*
    2）hash，T=O(n)，S=O(n)
*/
class Solution {
public:
    unordered_set<int> hash;
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        for (const auto& a : nums)
        {
            hash.insert(a);
        }
        for (const auto& a : hash) // 统计以a打头的最长连续序列
        {
            if (hash.find(a - 1) == hash.end()) // 如果能找到，那么a已经在以a-1打头的连续序列中算过一次了，且以a-1打头的最长序列肯定比以a打头的最长序列要长，所以a没必要再算一次
            {
                auto b = a;
                while (hash.find(b + 1) != hash.end()) ++b;
                res = max(res, b - a + 1);
            }
        }
        return res;
    }
};
