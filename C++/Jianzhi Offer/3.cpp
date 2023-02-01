/*
03. 数组中重复的数字
    在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。
    数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。
    请找出数组中任意一个重复的数字。

输入：
[2, 3, 1, 0, 2, 5, 3]
输出：2 或 3 
*/ 


/*
    1）hash算法，T=O(n)，S=O(n)
*/
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int n = nums.size();
        vector<int> mp(n, 0);
        for (int i = 0; i < nums.size(); i++)
        {
            if (mp[nums[i]] == 0)
            {
                mp[nums[i]] = 1;
            }
            else return nums[i];
        }
        return 0;
    }
};

/*
    2）利用数组特性求解，T=O(n)，S=O(1)
    长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内，因为数字局限在0～n-1内，所以我们可以遍历数组，将nums[i]尝试放在对应的nums[nums[i]]中
*/
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int i = 0;
        while (i < nums.size())
        {
            while (nums[i] != i && nums[nums[i]] != nums[i]) swap(nums[i], nums[nums[i]]);
            if (nums[i] == i) i++;
            else return nums[i];
        }
        return -1;
    }
};