// 57. 插入区间
// 给你一个 无重叠的 ，按照区间起始端点排序的区间列表。
// 在列表中插入一个新的区间，你需要确保列表中的区间仍然有序且不重叠（如果有必要的话，可以合并区间）。


/*
    插入+双指针，T=O(n)
    在56题的基础上，将newInterval插入到有序的intervals中，再进行区间合并
*/
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int k = 0;
        while (k < intervals.size())
        {
            if (newInterval[0] > intervals[k][0] || newInterval[0] == intervals[k][0] && newInterval[1] > intervals[k][1])
                ++k;
            else break;
        }
        intervals.insert(intervals.begin() + k, newInterval);

        vector<vector<int>> res;
        int i = 0, j = i + 1, maxRight = intervals[i][1];
        while (j < intervals.size())
        {
            if (maxRight >= intervals[j][1]) ;
            else if (maxRight >= intervals[j][0]) maxRight = intervals[j][1];
            else
            {
                res.emplace_back(vector<int>{intervals[i][0], maxRight});
                i = j;
                maxRight = intervals[i][1];
            }
            ++j;
        }
        res.emplace_back(vector<int>{intervals[i][0], maxRight});

        return res;
    }
};