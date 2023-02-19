// 56. 合并区间
// 以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。请你合并所有重叠的区间，并返回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。


/*
    排序+双指针，T=O(nlogn)
*/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end()); // 跟注释代码是等价的
        // sort(intervals.begin(), intervals.end(), [] (const vector<int>& a, const vector<int>& b) {
        //     if (a[0] == b[0]) return a[1] < b[1];
        //     return a[0] < b[0];
        // });

        vector<vector<int>> res;
        int i = 0, j = i + 1, maxRight = intervals[i][1];  // i, j双指针遍历；maxRight记录区间合并的最远R
        while (j < intervals.size())
        {
            // 排序完后，前一个区间的R跟后一个区间比较有三种情况：
            if (maxRight >= intervals[j][1]) ; // 1）R比后一个区间的R‘还要大，则前面一个区间可以包含后面一个区间
            else if (maxRight >= intervals[j][0]) maxRight = intervals[j][1]; // 2）R在后一个区间内，则更新maxRight为R'
            else // 3）R比后一个区间的L'要小，则两个区间不重叠
            {
                res.emplace_back(vector<int>{intervals[i][0], maxRight});
                i = j;
                maxRight = intervals[i][1];
            }
            ++j;
        }
        res.emplace_back(vector<int>{intervals[i][0], maxRight}); // 保存最后一个区间

        return res;
    }
};