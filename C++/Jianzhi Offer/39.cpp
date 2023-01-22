// 剑指 Offer 39. 数组中出现次数超过一半的数字

/*
    1）直接排序法，T=O(nlogn), S=O(1)
*/

/*
    2）hash算法，T=O(n), S=O(n)
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size(), cnt = (n + 1) / 2;
        map<int, int> mp;
        for (auto a : nums)
        {
            if (++mp[a] == cnt)
                return a;
        }
        return 0;
    }
};

/*
    3）根据数组特点的算法（摩尔投票法），T=O(n), S=O(1)
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 1, num = nums[0], n = nums.size(); // cnt记录次数，num记录当前的众数
        for (int i = 1; i < n; i++)
        {
            if (nums[i] == num) cnt++;
            else 
            {
                if (--cnt == 0) 
                {
                    cnt = 1;
                    num = nums[i];
                }
            }
        }
        return num;
    }
};

/*
    4）基于快排中的Partition函数，T=O(n), S=O(1)
    ps: 按理说这种算法的时间复杂度也是O(n)的，但是leetcode上会timeout，可能基于快排的思想在最差的情况时间复杂度会到O(n^2)
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size(), mid = (n - 1) / 2;
        int k = partition(0, n - 1, nums);
        int start = 0, end = n - 1;
        while (k != mid)
        {
            if (k > mid) 
            {
                end = k - 1;
                k = partition(start, end, nums);
            }
            else 
            {
                start = k + 1;
                k = partition(start, end, nums);
            }
        }
        return nums[mid];
    }
    int partition(int start, int end, vector<int>& nums)
    {
        int range = end - start + 1;
        int random_index = rand() % range + start;
        swap(nums[random_index], nums[end]);
        int index = start - 1;
        for (int i = start; i < end; i++)
        {
            if (nums[i] <= nums[end])
            {
                ++index;
                if (index != i) 
                {
                    swap(nums[index], nums[i]);
                }
            }
        }
        ++index;
        swap(nums[index], nums[end]);
        return index;
    }
};