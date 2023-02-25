// 204. 计数质数

/*
    素数筛发，T=O(nloglogn)，S=O(n)
*/
class Solution {
public:
    int countPrimes(int n) {
        vector<int> isPrimes(n, 1);
        for (int i = 2; i < n; i++)
        {
            if (isPrimes[i])
            {
                for (long long j = static_cast<long long>(i) * i; j < n; j += i)
                {
                    isPrimes[j] = 0;
                }
            }
        }
        int res = 0;
        for (int i = 2; i < n; i++)
        {
            if (isPrimes[i]) ++res;
        }
        return res;
    }
};