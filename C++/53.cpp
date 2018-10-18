/*
思路：
    动态规划（dp）：
    dp[i]即表示为以nums[i]结尾的连续字串和的最大值，
    则dp[i] = max(dp[i-1]+a[i], a[i]); max(dp[i]),0<=i<n,即为所求。
    
    分治法（divide and conquer):
    最大连续字串和肯定为以下三者之一：
    1.左最大连续字串
    2.右最大连续字串
    3.以mid为右边界的左最大连续字串 + 以mid+1为左边界的右最大连续字串
    
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(), ans = nums[0];
        // return dp(n, ans, nums);
        // return dpSaveSpace(n, ans, nums);
        return divideAndConquer(0, n - 1, nums);
    }
    //dp1
    int dp(int n, int ans, vector<int>& a){
        vector<int> f(n);
        f[0] = a[0];
        for(int i = 1; i < n; i++){
            f[i] = max(f[i - 1] + a[i], a[i]);
            ans = max(ans, f[i]);
        }
        return ans;
    }
    //dp2
    int dpSaveSpace(int n, int ans, vector<int>& a){
        int f = a[0];
        for(int i = 1; i < n; i++){
            f = max(f + a[i], a[i]);
            ans = max(ans, f);
        }
        return ans;
    }
    //分治法
    int divideAndConquer(int le, int ri, vector<int>& a){
        if(le == ri)
            return a[le];
        int mid = (le + ri) >> 1;
        int lmax = divideAndConquer(le, mid, a); // 1
        int rmax = divideAndConquer(mid + 1, ri, a); // 2
        
        int mlmax = a[mid], mrmax = a[mid + 1];
        int mlsum = 0;
        for(int i = mid; i >= le; i--){
            mlsum += a[i];
            mlmax = max(mlmax, mlsum);
        }
        int mrsum = 0;
        for(int i = mid + 1; i <= ri; i++){
            mrsum += a[i];
            mrmax = max(mrmax, mrsum);
        }
        int mmax = mlmax + mrmax; // 3
        return max(mmax, max(lmax, rmax));
    }
};