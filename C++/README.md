# ideas

* 53、[Maximum Subarray](https://github.com/QiuBiuBiu/LeetCode/blob/master/C%2B%2B/53.cpp)<br>
    动态规划（dp）：<br>
    dp[i]即表示为以nums[i]结尾的连续字串和的最大值，<br>
    则dp[i] = max(dp[i-1]+a[i], a[i]); max(dp[i]),0<=i<n,即为所求。<br>

    分治法（divide and conquer)：<br>
    最大连续字串和肯定为以下三者之一：<br>
    1.左最大连续字串<br>
    2.右最大连续字串<br>
    3.以mid为右边界的左最大连续字串 + 以mid+1为左边界的右最大连续字串<br>
