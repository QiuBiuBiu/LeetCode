// 剑指 Offer 29. 顺时针打印矩阵

/*
    模拟题，
    1）用n, m, top, left四个变量来更新边界值
    2）每次先按 向右，向下，向左，向上 的顺序遍历数组
    3）k值记录已遍历的数目，注意在任意方向遍历结束后，都可能结束遍历（用k != total - 1来结束遍历）
*/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int i = 0, j = 0;
        if (matrix.size() == 0) 
            return vector<int>{};
        int n = matrix.size(), m = matrix[0].size(), top = 0, left = -1, total = n * m;
        vector<int> res(total, 0);
        int k = -1;
        while (k != total - 1)
        { 
            while (j < m && k != total - 1) res[++k] = matrix[i][j++];
            m--, j--, i++; // 一个方向遍历结束后，更新边界值m，j因为遍历完成后越界了需要更新，更新i的值进入下一个方向的遍历
            while (i < n && k != total - 1) res[++k] = matrix[i++][j];
            n--, i--, j--;
            while (j > left && k != total - 1) res[++k] = matrix[i][j--];
            left++, j++, i--;
            while (i > top && k != total - 1) res[++k] = matrix[i--][j];
            top++, i++, j++;
        }
        return res;
    }
};