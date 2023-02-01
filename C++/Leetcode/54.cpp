/*
54. 螺旋矩阵
    给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。

    输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
    输出：[1,2,3,6,9,8,7,4,5]
*/

/*
    二维数组遍历，T=O(n^2), S=O(n)
    设置上下左右四个边界值来模拟向四个方向的遍历
*/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size(), total = n * m;
        int left = 0, right = m - 1, top = 1, bottom = n - 1;
        int i = 0, j = -1, k = -1;
        vector<int> res(n * m);
        while (k != total - 1)
        {
            while (j < right && k != total - 1) res[++k] = matrix[i][++j];
            --right;
            while (i < bottom && k != total - 1) res[++k] = matrix[++i][j];
            --bottom;
            while (j > left && k != total - 1) res[++k] = matrix[i][--j];
            ++left;
            while (i > top && k != total - 1) res[++k] = matrix[--i][j];
            ++top;
        }
        return res;
    }
};