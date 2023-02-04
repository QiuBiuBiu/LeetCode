/*
354. 俄罗斯套娃信封问题
    给你一个二维整数数组 envelopes ，其中 envelopes[i] = [wi, hi] ，表示第 i 个信封的宽度和高度。
    当另一个信封的宽度和高度都比这个信封大的时候，这个信封就可以放进另一个信封里，如同俄罗斯套娃一样。
    请计算 最多能有多少个 信封能组成一组“俄罗斯套娃”信封（即可以把一个信封放到另一个信封里面）。
*/

/*
    PS：此题是300题的二维扩展，由于此题数据量较大，所以动态规划方法TLE
    1）动态规划，T=O(n^2)，S=O(n)
    记f[i]为以i封信为最外层信封的最多信封序列。因为信封一开始是无序的，所以我们需要对其排序。
*/
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](vector<int>& a, vector<int>& b){
            if (a[0] == b[0]) return a[1] < b[1];
            return a[0] < b[0];
        });
        int res = 1;
        vector<int> f(envelopes.size(), 1);

        for (int i = 0; i < envelopes.size(); i++)
        {
            for (int j = 0; j < envelopes.size(); j++)
            {
                if (envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1])
                {
                    f[i] = max(f[i], f[j] + 1);
                }
            }
            res = max(res, f[i]);
        }
        return res;
    }
};


/*
    2）二分法，T=O(nlogn)，S=O(n)

*/
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](vector<int>& a, vector<int>& b){
            if (a[0] == b[0]) return a[1] > b[1]; // 注意这里，我们排序时，当宽度一致时，我们把高度按从大到小排序，而不是从小大到排（因为如果高度从小大到排序，可能导致高度一致的两封信封却被塞进了一起）
            return a[0] < b[0];
        });
        int k = -1;
        vector<int> cpy(envelopes.size()); // 因为宽度已经按照从小大到排好了，后面的信封的宽度一定大于等于前面的信封，所以我们只用考虑高度的情况来做二分
        for (int i = 0; i < envelopes.size(); i++)
        {
            if (i == 0) cpy[++k] = envelopes[i][1];
            else
            {
                if (envelopes[i][1] > cpy[k])
                {
                    cpy[++k] = envelopes[i][1];
                }
                else
                {
                    int le = 0, ri = k;
                    while (le != ri)
                    {
                        int mid = (ri - le) / 2 + le;
                        if (envelopes[i][1] > cpy[mid]) le = mid + 1;
                        else ri = mid;
                    }
                    cpy[le] = envelopes[i][1];
                }
            }
        }
        return k + 1;
    }
};

