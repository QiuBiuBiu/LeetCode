// 剑指 Offer 57 - II. 和为s的连续正数序列

/*
    1）枚举i~j之间的和，最差情况T=O(n^2)，n=target
*/
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> res;
        if (target < 3) return res;

        vector<pair<int, int>> seq;
        for (int i = 1; i <= target / 2; i++)
        {
            int sum = i;
            for (int j = i + 1; j <= (target + 1) / 2; j++)
            {
                sum += j;
                if (sum == target)
                {
                    seq.push_back(pair<int, int>{i, j});
                }
                else if (sum > target) break;  // 剪枝
            }
        }

        for (int i = 0; i < seq.size(); i++) // 记录结果
        {
            vector<int> tmp(seq[i].second - seq[i].first + 1);
            for (int k = seq[i].first; k <= seq[i].second; k++) 
                tmp[k - seq[i].first] = k;
            res.push_back(tmp);
        }
        return res;
    }
};

/*
    2）利用求和公式将1）的第二个循环替代为二分查找，T=O(nlogn)，n=target
    ps：实际运行环境第二种解法似乎并没有第一种解法(可能剪枝导致运行快了很多)运行时间快
*/
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> res;
        if (target < 3) return res;

        vector<pair<int, int>> seq;
        for (int i = 1; i <= target / 2; i++)
        {
            int j = find(i, i + 1, (target + 1) / 2, target); // 二分查找是否有满足的j值使得i～j之间的和等于target
            if (j > i) seq.push_back(pair<int, int>{i, j});
        }

        for (int i = 0; i < seq.size(); i++) // 记录结果
        {
            vector<int> tmp(seq[i].second - seq[i].first + 1);
            for (int k = seq[i].first; k <= seq[i].second; k++) 
                tmp[k - seq[i].first] = k;
            res.push_back(tmp);
        }
        return res;
    }

    int find(int n, int le, int ri, int target)
    {
        if (le > ri) return -1;
        int m = (le + ri) / 2;
        double tmp = 1.0 * (m + n) * (m - n + 1);  // 注意这里的乘积可能会导致int溢出
        if (fabs(2.0 * target - tmp) <= 0.000001) 
        {
            return m;
        }
        else if (2.0 * target < tmp) return find(n, le, m - 1, target);
        else return find(n, m + 1, ri, target);
    }
};

/*
    3）双指针，滑动窗口，T=O(n)，n=target
    57_1的思路同样适用于这道题，即有序数列的查找很适合使用双指针的解法
*/
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> res;
        if (target < 3) return res;

        int i = 1, j = 2, sum = 3;
        while (i < j && j <= (target + 1) / 2)
        {
            if (sum == target)
            {
                vector<int> tmp(j - i + 1);
                for (int k = i; k <= j; k++)
                    tmp[k - i] = k;
                res.push_back(tmp);

                sum += ++j;
            }
            else if (sum < target) sum += ++j;
            else sum -= i++;
        }
        return res;
    }
};
