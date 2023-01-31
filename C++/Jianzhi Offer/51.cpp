// 剑指 Offer 51. 数组中的逆序对

/*
    归并排序，T=O(nlogn), S=O(n)
    归并排序可以理解成一个二叉树，算法主要分为两步：
    1）分而治之，直到单一节点(st == end) O(logn)
    2）在父节点完成对两个子节点（两个都是已排好序的数列）排序 O(n)
    需要借助一个copy数组来更新原数组，所以归并排序是用空间换时间。
*/

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        vector<int> copy(nums);
        return getPairs(copy, nums, 0, nums.size() - 1);
    }
    int getPairs(vector<int>& copy, vector<int>& nums, int st, int end)
    {
        if (st >= end)
        {
            return 0;
        }

        int mid = (end - st) / 2 + st;
        int left = getPairs(copy, nums, st, mid); // 1）
        int right = getPairs(copy, nums, mid + 1, end); // 1）

        int i = mid, j = end;
        int indexCopy = j;
        int cnt = 0;
        while (i >= st && j > mid) // 2）
        {
            if (nums[i] > nums[j])
            {
                cnt += j - mid;
                copy[indexCopy--] = nums[i--];
            }
            else
            {
                copy[indexCopy--] = nums[j--];
            }
        }
        while (i >= st) copy[indexCopy--] = nums[i--];
        while (j > mid) copy[indexCopy--] = nums[j--];

        for (int k = st; k <= end; k++) nums[k] = copy[k]; // 用copy来更新nums，即完成这个区间的排序

        return left + right + cnt;
    }
};