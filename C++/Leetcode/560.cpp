/*
思路：
    brute force:
    暴力维护前k（0<=k<=n）项和，通过枚举s[j]-s[i]==k？依次判断i-1~j的连续项之和是否为k.
    hash table:
    哈希以O(1)的时间复杂度知道s[i]对应的k-s[i]有几个,明显降低了时间复杂度.
*/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // return bruteForce(nums, k);
        return hashTable(nums, k)
    }
    int bruteForce(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0, sum = 0;
        vector<int> s(n + 1);
        s[0] = 0;
        for (int i = 1; i <= n; i++) {
            sum += nums[i - 1];
            s[i] = sum;
        }
        for (int i = 0; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (s[j] - s[i] == k) {
                    ans++;
                }
            }
        }
        return ans;
    }
    int hashTable(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0, sum = 0;
        map<int, int> m;
        m[0] = 1;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            ans += m[sum - k];
            m[sum] += 1;
        }
        return ans;
    }
};