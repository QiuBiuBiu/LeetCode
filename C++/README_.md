# ideas

* 20、[Generate Parentheses](https://github.com/QiuBiuBiu/LeetCode/blob/master/C%2B%2B/22.cpp)<br>
    **二维的回溯法（back tracking & DFS）**
    > 用l和r记录还剩余可用的左括号和有括号的数目。<br>

* 53、[Maximum Subarray](https://github.com/QiuBiuBiu/LeetCode/blob/master/C%2B%2B/53.cpp)<br>
    **动态规划（dp）**
    > dp[i]即表示为以nums[i]结尾的连续字串和的最大值，则dp[i] = max(dp[i-1]+a[i], a[i]); max(dp[i]),0<=i<n,即为所求。

    **分治法（divide and conquer）**
    > 最大连续字串和肯定为以下三者之一：<br>
    >> 1.左最大连续字串<br>
    >> 2.右最大连续字串<br>
    >> 3.以mid为右边界的左最大连续字串 + 以mid+1为左边界的右最大连续字串<br>

* 152、[Maximum Product Subarray](https://github.com/QiuBiuBiu/LeetCode/blob/master/C%2B%2B/152.cpp)<br>
    **动态规划（dp）**
    > 与53.Maximum Subarry的状态及状态转移相似。只是由于负负相乘为正的关系，这里需要维护两个数组。最大值从其中一个数组中产生。
