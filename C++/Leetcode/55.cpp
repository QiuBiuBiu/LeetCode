// 55. 跳跃游戏
// 给定一个非负整数数组 nums ，你最初位于数组的 第一个下标 。
// 数组中的每个元素代表你在该位置可以跳跃的最大长度。
// 判断你是否能够到达最后一个下标。


/*
    DP，T=O(n^2)，S=O(n)
*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> f(n, false); // 定义以i为起点是否能到达终点
        f[n - 1] = true; // 初值
        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[i] != 0) // 剪枝
            {
                if (i + nums[i] >= n - 1) f[i] = true; // 剪枝
                else
                {
                    for (int j = i + 1; j <= i + nums[i]; j++) // i自身可以到达j
                    {
                        if (f[j]) // 如果j可以到达终点，那么i也可以到达
                        {
                            f[i] = true;
                            break; // 剪枝
                        }
                    }                    
                }

            }
        }
        return f[0]; // 最终答案
    }
};

/*
    贪心，T=O(n)，S=O(1)
    维护一个从起点0开始最远能跳到的距离range
    如果最终能到达终点的话，那么一步一步地也能到达终点（为0的点需要跨过）
*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int range = 0; // 初始值
        for (int i = 0; i < nums.size(); i++)
        {
            range = max(range, i + nums[i]); // 每跳到一个点，更新一下当前能到达的最远距离
            if (range >= nums.size() - 1) return true; // 如果能到达终点了，返回true
            if (range == i) return false; // 如果到达i点并且最远能到达的距离还是i，那么返回false
        }
        return true;
    }
};