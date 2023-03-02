// 169. 多数元素
// 给定一个大小为 n 的数组 nums ，返回其中的多数元素。多数元素是指在数组中出现次数 大于 ⌊ n/2 ⌋ 的元素。


/*
    默尔投票法，T=O(n), S=O(1)
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 1, res = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == res) ++cnt;
            else 
            {
                if (cnt == 1) res = nums[i];
                else --cnt;
            }
        }
        return res;
    }
};
