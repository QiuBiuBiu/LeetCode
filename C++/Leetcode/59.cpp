/*
59. 螺旋矩阵 II
    给你一个正整数 n ，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。

    输入：n = 3
    输出：[[1,2,3],[8,9,4],[7,6,5]]
*/

/*
    二维数组遍历，T=O(n^2), S=O(n^2)
    和54.cpp思路一样，设置上下左右四个边界值来模拟向四个方向的遍历
*/
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));
        int left = 0, right = n - 1, top = 1, bottom = n - 1, total = n * n;
        int i = 0, j = -1, k = 0;
        while (k != total)
        {
            while (j < right && k != total) matrix[i][++j] = ++k;
            --right;
            while (i < bottom && k != total) matrix[++i][j] = ++k;
            --bottom;
            while (j > left && k != total) matrix[i][--j] = ++k;
            ++left;
            while (i > top && k != total) matrix[--i][j] = ++k;
            ++top;
        }
        return matrix;
    }
};