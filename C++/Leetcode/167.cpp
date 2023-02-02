/*
167. 两数之和 II - 输入有序数组
    给你一个下标从 1 开始的整数数组 numbers ，该数组已按 非递减顺序排列  ，请你从数组中找出满足相加之和等于目标数 target 的两个数。
    如 果设这两个数分别是 numbers[index1] 和 numbers[index2] ，则 1 <= index1 < index2 <= numbers.length 。

    输入：numbers = [2,7,11,15], target = 9
    输出：[1,2]
*/

/*
    双指针，T=O(n)，S=O(1)
    有别于第1题，这题中的数字是有序排列的，所以我们可以使用一前一后两个指针
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = numbers.size() - 1;
        while (i < j)
        {
            int sum = numbers[i] + numbers[j];
            if (sum > target) --j;
            else if (sum < target) ++i;
            else return vector<int>{i + 1, j + 1};
        }
        return vector<int>{};
    }
};