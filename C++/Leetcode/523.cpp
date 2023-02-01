/*
思路：
	hash，思路和560相似
	map<i,j>映射前i项和下标i
*/
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        // return bruteForce(n, nums, k);
        return hashTable(n, nums, k);
    }
    int bruteForce(int n, vector<int>& a, int k) {
        vector<int> s(n + 1);
        s[0] = 0;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += a[i];
            s[i + 1] = sum;
        }
        for (int i = 0; i < n + 1; i++) {
            for (int j = i + 2; j < n + 1; j++) {
                if (k && ((s[j] - s[i]) % k == 0)) {
                    return true;
                }
                else if(k == 0 && (s[j] - s[i] == 0)) {
                    return true;
                }
            }
        }
        return false;
        
    }
    int hashTable(int n, vector<int>& a, int k) {
        int sum = 0;
        map<int, int> m;
        m[0] = 0;
        for (int i = 1; i <= n; i++) {
            sum += a[i - 1];
            sum = k == 0 ? sum : sum % k;
            if (m.count(sum)) {
                if (i - m[sum] > 1)
                    return true;                
            }
            else
                m[sum] = i;
        }
        return false;
    }
};