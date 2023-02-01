/*
04. 二维数组中的查找
    在一个 n * m 的二维数组中，每一行都按照从左到右 非递减 的顺序排序，每一列都按照从上到下 非递减 的顺序排序。
    请完成一个高效的函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

    现有矩阵 matrix 如下：
    [
    [1,   4,  7, 11, 15],
    [2,   5,  8, 12, 19],
    [3,   6,  9, 16, 22],
    [10, 13, 14, 17, 24],
    [18, 21, 23, 26, 30]
    ]
    给定 target = 5，返回 true。
    给定 target = 20，返回 false。
*/

/*
    1）二分法，T=O(n * mlogm)
    每行都是递增的，所以可以逐行二分查找
*/
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        for (int i = 0; i < n; i++)
        {
            int m = matrix[i].size();
            int le = 0, ri = m - 1;
            while (le <= ri)
            {
                int mid = le + (ri - le) / 2;
                if (matrix[i][mid] < target) le = mid + 1;
                else if (matrix[i][mid] > target) ri = mid - 1;
                else return true;
            }
        }
        return false;
    }
};

/*
    2）利用数组特征，T=O(n + m)
    首先我们固定i = 0， j = m - 1, 即二维数组右上角的数字，然后开始跟target比较
    若大于，因为从上至下是递增的，所以排除j = m - 1这一列，j--
    小于则类似
*/
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if (n == 0) return false;
        int m = matrix[0].size();
        int i = 0, j = m - 1;
        while (i < n && j >= 0)
        {
            if (matrix[i][j] > target) j--;
            else if (matrix[i][j] < target) i++;
            else return true;
        }
        return false;
    }
};