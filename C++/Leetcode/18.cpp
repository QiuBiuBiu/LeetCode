/*
18. 四数之和
    给你一个由 n 个整数组成的数组 nums ，和一个目标值 target 。请你找出并返回满足下述全部条件且不重复的四元组 [nums[a], nums[b], nums[c], nums[d]] （若两个四元组元素一一对应，则认为两个四元组重复）：
    0 <= a, b, c, d < n
    a、b、c 和 d 互不相同
    nums[a] + nums[b] + nums[c] + nums[d] == target
    你可以按 任意顺序 返回答案 。

    输入：nums = [1,0,-1,0,-2,2], target = 0
    输出：[[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
*/


/*
    排序+双指针，T=O(n^3)，S=O(1)
    先排序，再固定两个数字nums[i]和nums[j]，用双指针来寻找另外两个数字
    PS：这种解法同样适用于15题，16题
*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            if (i == 0 || nums[i] != nums[i - 1]) // 去重
            {
                for (int j = i + 1; j < nums.size(); j++)
                {
                    if (j == i + 1 || nums[j] != nums[j - 1]) // 去重
                    {
                        for (int p = j + 1, q = nums.size() - 1; p < q; )
                        {
                            long long sum = static_cast<long long>(nums[i]) + nums[j] + nums[p] + nums[q]; // 有int溢出的case
                            if (sum > target) --q;
                            else if (sum < target) ++p;
                            else 
                            {
                                res.emplace_back(vector<int>{nums[i], nums[j], nums[p], nums[q]});
                                ++p, --q;
                                while (p < q && nums[p] == nums[p - 1]) ++p; // 去重
                                while (p < q && nums[q] == nums[q + 1]) --q; // 去重
                            }
                        }                    
                    }
                }
            }
        }
        return res;
    }
};