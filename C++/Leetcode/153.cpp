// 153. 寻找旋转排序数组中的最小值


/*
    二分，T=O(logn)，S=O(1)
    通过对mid可能出现的区间进行分析可知，只需要通过跟右指针进行比较。
    最终i=j，返回任意一个即可
*/
class Solution {
public:
    int findMin(vector<int>& nums) {
        int i = 0, j = nums.size() - 1;
        while (i < j)
        {
            int mid = i + (j - i) / 2;
            if (nums[mid] > nums[j])
            {
                i = mid + 1;
            }
            else
            {
                j = mid;
            }
        }
        return nums[i];
    }
};